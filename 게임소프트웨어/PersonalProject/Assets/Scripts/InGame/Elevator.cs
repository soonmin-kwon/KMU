using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// 위아래로 움직이는 발판
public class Elevator : MonoBehaviour
{
    GameObject obj;
    Rigidbody rigid;
    // 발판 움직이는 속도
    public float movespeed = 1.0f;
    // 발판이 움직이는 시간을 재기 위한 변수
    float time = 0.0f;
    int second = 0;
    // 발판이 움직이는 방향
    public float dir;
    // player의 방향
    float obj_dir = 1.0f;

    void Start()
    {
        obj = GameObject.Find("Cat");
    }
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

    // 발판 위에 있으면 플레이어가 회전하는데 그걸 막기 위한 함수
    public void OnCollisionStay(Collision other)
    {
        if(obj.transform.rotation.y < 0)
        {
            obj_dir = -1.0f;
        }
        else
        {
            obj_dir = 1.0f;
        }
        obj.transform.rotation = Quaternion.Euler(new Vector3(0, obj_dir * 90.0f, 0));   
    }
}
