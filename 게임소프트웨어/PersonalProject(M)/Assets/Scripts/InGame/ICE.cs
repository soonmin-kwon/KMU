using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// 얼음 발판을 밟은 것 처럼 표현
public class ICE : MonoBehaviour
{
    GameObject obj;                 
    float movespeed;        // 미끄러지는 속도
    float angle;            // 발판 접근 방향
    float check = 1;        // 처음 밟은건지 아닌지 체크
    void Start()
    {
        // 플레이어 체크
        obj = GameObject.Find("Cat");
    }
    // 발판을 밟았을 때, 미끄러지는 초기 속도설정과 밟았을 때 방향 확인
    public void OnCollisionEnter(Collision other)
    {
        // 같은 발판 내에서 점프인지 확인
        if (check == 1)
        {
            angle = obj.transform.rotation.y;
        }
        movespeed = 0.05f;
    }
    // 얼음 발판 효과
    public void OnCollisionStay(Collision other)
    { 
        movespeed *= 0.98f;
        // 발판을 밟았을 때 진입방향과 현재의 방향을 찾아서 미끄러지는 방향 설정
        if(angle < 0)
        {
            // 진입 방향과 현재 방향이 같을 때
            if(obj.transform.rotation.y < 0)
            {
                obj.transform.Translate(0, 0, movespeed);
            }
            // 다를 때
            else
            {
                obj.transform.Translate(0, 0, -movespeed);
            }
        }
        // 위와 동일
        else
        {
            if (obj.transform.rotation.y < 0)
            {
                obj.transform.Translate(0, 0, -movespeed);
            }
            else
            {
                obj.transform.Translate(0, 0, movespeed);
            }
        }
    }
    // 한 얼음 발판 내에서 점프하는 경우 방향 값 설정
    // 얼음 발판 1에서 점프해서 다시 얼음 발판1로 착지하면 밀려나는 방향이
    // 점프할 때 방향과 같아야 함.
    public void OnCollisionExit(Collision other)
    {
        angle = obj.transform.rotation.y;
        check++;
    }
}
