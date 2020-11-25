using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// 위아래로 움직이는 발판
public class Elevator : MonoBehaviour
{
    Rigidbody rigid;
    // 발판 움직이는 속도
    public float movespeed = 1.0f;
    // 발판이 움직이는 시간을 재기 위한 변수
    float time = 0.0f;
    int second = 0;
    // 발판이 움직이는 방향
    public float dir;

    // 발판이 스스로 움직이게 한다.
    void Update()
    {
        time += Time.deltaTime;
        second = (int)time % 60;
        // 3초마다 방향을 바꾼다.
        if(second%6 <=2)
        {
            transform.Translate(0, dir * movespeed * Time.deltaTime, 0);
        }
        else
        {
            transform.Translate(0, -dir * movespeed * Time.deltaTime, 0);
        }
    }
}
