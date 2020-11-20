using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//모바일 전용 스크립트
public class Teleport : MonoBehaviour
{
    // Start is called before the first frame update
    GameObject obj;
    GameObject butt;
    AudioSource audio;
    // 텔레포트 목적지 좌표
    public float x;
    public float y;
    public float z;
    
    void Start()
    {
        obj = GameObject.Find("Cat");
        butt = GameObject.Find("Move");
        audio = GetComponent<AudioSource>();
    }

    //  텔레포트 발판 위에 있을 때
    public void OnCollisionStay(Collision other)
    {
        // 위 방향키를 누르면 파티클이 실행되고 Tele함수를 1초 있다가 실행
        // 파티클 효과를 자연스럽게 하기 위해 Invoke 사용
        // 포탈 버튼을 누르면
        if (butt.GetComponent<MobileVersion>().upcheck)
        {
            Debug.Log(butt.GetComponent<MobileVersion>().upcheck);
            GetComponent<ParticleSystem>().Play();
            audio.Play();
            Invoke("Tele", 1);
            //Teleport 후 다시 false로
            butt.GetComponent<MobileVersion>().upcheck = false;
        }
        
    }
    // 실제 움직이는 함수
    public void Tele()
    {      
        obj.transform.position = new Vector3(x, y, z);

    }
}
