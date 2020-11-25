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
        // 메뉴가 닫혀있으면 ( 게임 플레이 중 )
        if (!menu.activeSelf)
        {
            // 정상속도로 움직인다.
            Time.timeScale = 1;
        }
    }
    // 왼쪽 방향키 클릭
    public void OnLeftClick()
    {
        // 왼쪽을 보게 한다.
        Player.GetComponent<Controller>().SetLeftDir();
    }
    // 오른쪽 방향키 클릭
    public void OnRightClick()
    {
        // 오른쪽을 보게 한다.
        Player.GetComponent<Controller>().SetRightDir();
    }
    // 포탈 버튼 클릭
    public void OnUpClick()
    {
        // 버튼을 누르면 true값으로 설정
        upcheck = true;
    }
    // Reset 버튼 클릭
    public void OnResetClick()
    {
        // Save가 되어있으면 세이브 포인트로, 그렇지 않으면 시작 지점으로 이동
        Player.GetComponent<Controller>().Load();
    }
    // 메뉴 버튼을 클릭
    public void OnMenuClick()
    {
        // 메뉴가 꺼져있으면
        if (!menu.activeSelf)
        {
            // 메뉴가 열리고
            menu.SetActive(true);
            // 퍼즈
            Time.timeScale = 0;
        }
    }
    // Intro 시에 skip버튼 클릭 시
    public void OnSkipClick()
    {
        skip.GetComponent<Camera>().check = 8;
    }
}
