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


    void Start()
    {
        obj = GameObject.Find("Cat");
        chicken = GameObject.Find("Chicken");
       
    }
    
    // 프레임마다 obj(Player)에 위치에 맞게 따라 위치를 설정
    void Update()
    {
        // 게임 시작 2초 뒤에 Intro 시작
        Invoke("CameraWalk",2.0f);
        // Intro가 끝났거나 skip을 누른 경우 카메라를 플레이어에 고정
        if(check == 8)
        {
            // intro가 끝났으면 카메라 고정
            Fix();          
        }      
    }
    // 카메라를 플레이어한테 고정
    void Fix() {
        transform.position = new Vector3(obj.transform.position.x, obj.transform.position.y + 2.5f, transform.position.z);
    }
    // 모든 맵을 한번 보여주는 함수 (Intro )
    void CameraWalk()
    {
        if (check == 0)
        {
            transform.Translate(-0.1f, 0.0f, 0.0f);
        }        
        if (check == 1)        
        {        
            transform.Translate(0.0f, -0.1f, 0.0f);            
        }        
        if (check == 2)        
        {        
            transform.Translate(0.095f, -0.03f, 0.0f);            
        }        
        if(check == 3)       
        {        
            transform.Translate(-0.096f, -0.03f, 0.0f);            
        }
        if(check == 4)        
        {        
            transform.Translate(0.147f, -0.02f, 0.0f);            
        }        
        if (check == 5)        
        {        
            transform.Translate(-0.143f, -0.018f, 0.0f);            
        }        
        if (check == 6)        
        {        
            transform.Translate(0.113f, -0.032f, 0.0f);            
        }        
        if (check == 7)        
        {        
            transform.Translate(-0.097f, -0.013f, 0.0f);            
        }
                              
        if ((int)transform.position.x == -26 && check == 0)        
        {                                
            check = 1;
        }        
        else if ((int)transform.position.y == 86 && check == 1)       
        {        
            check = 2;
        }        
        else if ((int)transform.position.y == 68 && check == 2)        
        {        
            check = 3;
        }      
        else if((int)transform.position.y == 50 && check == 3)        
        {        
            check = 4;
        }        
        else if ((int)transform.position.y == 38 && check == 4)        
        {
            check = 5;
        }        
        else if ((int)transform.position.y == 27 && check == 5)       
        {       
            check = 6;
        }       
        else if ((int)transform.position.y == 8 && check == 6)      
        {       
            check = 7;
        }        
        else if ((int)transform.position.y == 0 && check == 7)       
        {       
            check = 8;
        }

    }

    
}
