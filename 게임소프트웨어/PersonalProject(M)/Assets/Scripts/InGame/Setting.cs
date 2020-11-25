using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

// Back to Main 버튼 스크립트
public class Setting : MonoBehaviour
{
    // 게임 내 메뉴에서 메인으로 가는 버튼을 누르면
    public void OnClickBack()
    {
        //Fade class의 함수를 이용해 Fade in효과
        GameObject panel = GameObject.Find("Fade");
        panel.GetComponent<Fade>().FadeIn();
        Invoke("ChangeS", 1.5f); 
    }

    // 씬을 메인화면으로 바꿈
    public void ChangeS()
    {
        SceneManager.LoadScene("Start");
    }

}
