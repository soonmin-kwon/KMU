using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

//finish 지점
public class Chicken : MonoBehaviour
{
    
    Rigidbody rigid;
    Animator ani;
    //fade in 효과를 한번만 내기 위한 변수
    int check = 0;

    
    void Start()
    {
        rigid = GetComponent<Rigidbody>();
        ani = GetComponent<Animator>();
        StartCoroutine("Jumping");
    }

    // 스스로 3초마다 한번씩 점프하는 함수
    IEnumerator Jumping()
    {
        while (true)
        {
            if (this.rigid.velocity.y == 0)
            {
                this.rigid.AddForce(0, 300.0f, 0);
                ani.SetTrigger("jump");
            }
            yield return new WaitForSeconds(3.0f);
        }
    }
    
    // 치킨이 부딪혔을 때
    void OnCollisionEnter(Collision other)
    {
        // 고양이와 만나면
        if(other.gameObject.tag == "Player")
        {
            check++;
            // Fade in 효과
            if (check == 1)
            {
                GameObject pan = GameObject.Find("Fade");
                pan.GetComponent<Fade>().FadeIn();
                Invoke("change", 1.5f);
            }
            // 1.5초 뒤 클리어 씬으로 변경
        }
    }
    // 씬 변경 함수
    public void change()
    {
        SceneManager.LoadScene("Clear");
    }
}
