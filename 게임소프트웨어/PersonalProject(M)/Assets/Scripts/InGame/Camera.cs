using System.Collections;
using System.Collections.Generic;
using UnityEngine;

// 카메라의 위치를 Cat(Player)에 맞춰서 움직이게끔 하는 스크립트
public class Camera : MonoBehaviour
{
    
    public int check=0;
    GameObject obj;
    // finish 지점
    GameObject chicken;
    // skip 버튼
    GameObject skip;

    void Start()
    {
        obj = GameObject.Find("Cat");
        chicken = GameObject.Find("Chicken");
        
    }
    // 프레임마다 obj(Player)에 위치에 맞게 따라 위치를 설정
    void Update()
    {
        // 게임 시작 2초 뒤에 카메라 고정 시작
        Invoke("Fix", 2.0f);           
    }
    // 카메라를 플레이어한테 고정
    void Fix() {
        transform.position = new Vector3(obj.transform.position.x, obj.transform.position.y + 2.5f, transform.position.z);
    }
    
}
