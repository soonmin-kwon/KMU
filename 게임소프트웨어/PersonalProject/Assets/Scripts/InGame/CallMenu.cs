using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//메뉴창 스크립트
public class CallMenu : MonoBehaviour
{
    
    public GameObject menu;

   
    void Update()
    {
        //esc키 입력
        if (Input.GetKeyDown(KeyCode.Escape))
        {
            // menu창이 열려 있지 않으면 메뉴창을 연다.
            if (!menu.activeSelf)
            {
                menu.SetActive(true);
                //pause
                Time.timeScale = 0;
            }
            
        }
        // 닫혀있으면
        if (!menu.activeSelf)
        {
            // 정상속도로 움직인다.
            Time.timeScale = 1;
        }

    }
}
