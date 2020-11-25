using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// 세이브 포인트에 적용하는 스크립트
public class Apple : MonoBehaviour
{
    // 사과가 돌아가는 속도
    // 가만히 있으면 심심할 것 같아서 움직이게 만들었다.
    public float speed = 60.0f;
    AudioSource audio2;
    void Start()
    {
        this.audio2 = GetComponent<AudioSource>();
    }
    void Update()
    {
        // 회전
        transform.Rotate(0,speed * Time.deltaTime, 0);
    }
    // 플레이어가 사과를 먹었을 때
    public void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "Player") 
        {            
            //사과를 먹는 효과음
            audio2.Play();
            // 효과음을 실행하기 위해 효과음이 나오면 세이브포인트 삭제
            Invoke("del", 0.3f);
        }
    }

    // 사과 오브젝트 삭제
    public void del()
    {
        Destroy(this.gameObject);
    }

}
