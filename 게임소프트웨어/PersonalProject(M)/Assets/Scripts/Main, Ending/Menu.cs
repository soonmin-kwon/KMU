using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class Menu : MonoBehaviour
{
    public Image fade;
    public Color color;
    public string name;
    void Start()
    {
        fade = GetComponent<Image>();
    }

    //게임 시작 버튼을 누르면 페이드 인, 씬 전환
    public void OnClickStart()
    {
        FadeIn(name);
    }
    // exit 버튼을 누르면 어플 종료
    public void OnClickExit()
    {
        Debug.Log("Quit!");
        Application.Quit();
    }
    // Fade in
    public void FadeIn(string name)
    {
        StartCoroutine("FadeI", name);
    }

    //실질적인 Fade In을 실행하는 함수
    public IEnumerator FadeI(string name)
    {
        for (float f = 0.0f; f <= 1.0f; f += 0.1f)
        {
            color = fade.color;
            color.a = f;
            fade.color = new Color(0, 0, 0, color.a);
            yield return new WaitForSeconds(.1f);
        }
        fade.color = new Color(0, 0, 0, 1);
        SceneManager.LoadScene(name);
    }
}