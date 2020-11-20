using System.Collections;
using System.Collections.Generic;
using UnityEngine;


// 모바일 용 스크립트
public class MobileVersion : MonoBehaviour
{
    
    GameObject Player;
    GameObject skip;
    public GameObject menu;
    public bool upcheck;
    
    void Start()
    {
        Player = GameObject.Find("Cat");
        skip = GameObject.Find("Main Camera");
    }
    void Update()
    {
        // 메뉴가 닫혀있으면
        if (!menu.activeSelf)
        {
            // 정상속도로 움직인다.
            Time.timeScale = 1;
        }

    }
    // 왼쪽 방향키 클릭
    public void OnLeftClick()
    {
        Player.GetComponent<Controller>().SetLeftDir();
    }
    // 오른쪽 방향키 클릭
    public void OnRightClick()
    {
        Player.GetComponent<Controller>().SetRightDir();
    }
    // 포탈 버튼 클릭
    public void OnUpClick()
    {
        upcheck = true;
    }
    // Reset 버튼 클릭
    public void OnResetClick()
    {
        Player.GetComponent<Controller>().Load();
    }
    // 메뉴 버튼을 클릭
    public void OnMenuClick()
    {
        if (!menu.activeSelf)
        {
            menu.SetActive(true);
            //pause
            Time.timeScale = 0;
        }
    }
    // Intro 시에 skip버튼 클릭 시
    public void OnSkipClick()
    {
        skip.GetComponent<Camera>().check = 8;
    }
}
