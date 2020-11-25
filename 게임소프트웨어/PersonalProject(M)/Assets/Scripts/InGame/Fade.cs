using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
// Fade In, out 효과를 내는 함수
public class Fade : MonoBehaviour
{
 
    public Image fade;
    public Color color;
     
    void Start()
    {
        fade = GetComponent<Image>();
        StartCoroutine("FadeOut");
    }

    // 게임 시작 시 Fade Out 효과
    IEnumerator FadeOut()
    {
        for (float f = 1.0f; f >= 0.0f; f -= 0.1f)
        {
            color = fade.color;
            color.a = f;
            fade.color = new Color (0, 0, 0, color.a);
            yield return new WaitForSeconds(.1f);
        }
        fade.color = new Color(0, 0, 0, 0);
    }

    //Fade In 효과를 내는 함수
    public void FadeIn()
    {
        StartCoroutine("FadeI");
    }

    //실질적인 Fade In을 실행하는 함수
    public IEnumerator FadeI()
    {
        for (float f = 0.0f; f <= 1.0f; f += 0.1f)
        {
            color = fade.color;
            color.a = f;
            fade.color = new Color(0, 0, 0, color.a);
            yield return new WaitForSeconds(.1f);
        }
        fade.color = new Color(0, 0, 0, 1);
        
    }
}
