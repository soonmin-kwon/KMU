using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//볼륨 조정 기능
public class Volume : MonoBehaviour
{
    public AudioSource music;

    // 슬라이더를 이용해 볼륨을 조정
    public void SetMusicVolume(float volume)
    {
        music.volume = volume;
    }
}
