using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// 모바일 전용
public class Controller : MonoBehaviour
{
    
    // 변수 선언
    Rigidbody rigid;
    Animator anim;
    AudioSource audio; 
    // 변수 default
    public float x = -15.0f, y=0.0f, z = 8.5f;
    public float rx = 0.0f, ry = 90.0f, rz = 0.0f;
    // y방향 점프력, x방향 점프력
    float forceY = 0.0f;
    float forceX = 0.0f;
    public float key = 1.0f;   // 점프 방향 설정 1이면 오른쪽, -1이면 왼쪽
    int check = 0;      // 두번 이상 점프하지 못하도록 설정
    // 컴포넌트 설정
    void Start()
    {
        this.rigid = GetComponent<Rigidbody>();
        this.anim = GetComponent<Animator>();
        this.audio = GetComponent<AudioSource>();
    }
    // 발판에 올라갔을 때 다시 점프가 가능하게 해준다.
    public void OnCollisionEnter(Collision other)
    {
        check = 1;
    }
    // 방향키와 땅에 정확히 닿아 있는지 확인해서 방향을 설정해주는 기능
    // 오른쪽을 바라보는 함수
    public void SetRightDir()
    {        
        if (this.transform.rotation.y != 90.0f && (int)this.transform.rotation.x == 0.0f && (int)this.transform.eulerAngles.z == 0.0f && check ==1)
        {
            // 땅에 정확히 닿아 있는지
            if ((int)this.transform.eulerAngles.x == 0)
            {
                // 방향키에 맞게끔 회전
                this.transform.rotation = Quaternion.Euler(new Vector3(0.0f, 90.0f, 0.0f));
                key = 1.0f;
                anim.SetTrigger("Walk");
            }
        }
    }
    // 왼쪽을 바라보는 함수
    public void SetLeftDir()
    {
        if (this.transform.rotation.y != -90.0f && (int)this.transform.rotation.x == 0.0f && (int)this.transform.eulerAngles.z == 0.0f && check == 1)
        {

            if ((int)this.transform.eulerAngles.x == 0)
            {
                this.transform.rotation = Quaternion.Euler(new Vector3(0.0f, -90.0f, 0.0f));
                key = -1.0f;
                anim.SetTrigger("Walk");
            }
        }
    }
    // 점프 기능
    // 점프 키를 누르고 있을 때 점프력이 점점 올라간다.
    public void Jumpdown()
    {
        forceY += Time.deltaTime * 300.0f;
        forceX += Time.deltaTime * 300.0f;
    }
    // 스페이스바를 때면 점프가 진행된다.
    public void Jump()
    {      
        // player의 속도, 회전을 판단하고 점프가 가능한 상태인지 판단
        if (((int)this.transform.eulerAngles.x == 0) && check == 1)
        {
            // 점프력이 무한정 커지는 걸 막기 위해 일정 수준이 넘어가면 그 수준을 넘지 못하도록 한다.
            if (forceY > 300)        
            {
                forceY = 300;     
            }    
            if (forceX > 200)     
            {
                forceX = 200;
            }
             // 대각선 점프
             rigid.AddForce(key*forceX, 100+forceY,  0);
             // 점프를 하면 플레이어의 방향을 설정
             this.transform.rotation = Quaternion.Euler(new Vector3(0, key * 90.0f, 0));
             // 애니메이션 실행
             anim.SetTrigger("jump");
             // 효과음
             audio.Play();
             // 점프 불가 상태
             check --;
        }
        // force 초기화
        forceY = 0.0f;
        forceX = 0.0f;
    }
    // 저장한 상태를 로드
    // default = 시작 지점
    public void Load()
    {
        this.transform.position = new Vector3(x, y, z);
        this.transform.rotation = Quaternion.Euler(new Vector3(rx, 90.0f, rz));
        key = 1.0f;
    }
    // 현재 상태를 저장
    public void Save()
    {
        this.x = transform.position.x;
        this.y = transform.position.y;
        this.z = transform.position.z;
        this.rx = transform.eulerAngles.x;
        this.rz = transform.eulerAngles.z;
    }
    // 사과(세이브 포인트)를 먹으면 현재 위치를 저장.
    public void OnTriggerEnter(Collider other)
    {
        if(other.gameObject.tag == "apple")
        {
            Save();   
        }
    }
}
