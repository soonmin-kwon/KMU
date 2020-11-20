using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// 계속 미끄러지는 발판
public class Treadmill : MonoBehaviour
{
    
    GameObject obj;
    // 미끄러지는 속도
    public float movespeed = -0.05f;
    public float dir = 1.0f;
    void Start()
    {
        obj = GameObject.Find("Cat");
    }

    // 발판에 닿아 있으면 계속 미끄러진다.
    public void OnCollisionStay(Collision other)
    {
        if(dir * obj.transform.rotation.y < 0)
        {
            obj.transform.Translate(0, 0, movespeed);
        }
        else
        {
            obj.transform.Translate(0, 0, -movespeed);
        }
    }  
}
