using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// Save Point
public class Apple : MonoBehaviour
{
    // 사과가 돌아가는 속도
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
            audio2.Play();
            Invoke("del", 1);

        }
    }

    // 사과 오브젝트 삭제
    public void del()
    {
        Destroy(this.gameObject);
    }

}
