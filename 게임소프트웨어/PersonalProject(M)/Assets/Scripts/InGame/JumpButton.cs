using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.EventSystems;

// 모바일 용 점프 버튼
// 버튼을 누르고 떼는 순간을 체크하기 위해 IPointerDownHandler, IPointerUpHandler를 Implement함
public class JumpButton : MonoBehaviour, IPointerDownHandler, IPointerUpHandler
{
    GameObject Player;
    bool jumpdown = false;
    void Start()
    {
        Player = GameObject.Find("Cat");
    }

    void Update()
    {
        // jumpdown이 true이면, -> 버튼을 누르고 있으면
        if (jumpdown)
        {
            // 점프 힘을 모은다.
            Player.GetComponent<Controller>().Jumpdown();
        }
    }

    //버튼을 누르면
    public void OnPointerDown(PointerEventData butt)
    {
        jumpdown = true;        
    }
    //버튼을 떼면
    public void OnPointerUp(PointerEventData butt)
    {   
        Player.GetComponent<Controller>().Jump();
        jumpdown = false;
    }
}
