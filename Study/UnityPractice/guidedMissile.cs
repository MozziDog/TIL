//유도 미사일 구현해보기
//테스트는 안해봄

using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GuidedMissile : MonoBehaviour {

    public GameObject target;
    public float MaxDeltaAngle;
    public float speed;
    
    //================================
    private bool homing;
    private Transform targetTransform;
    private Transform thisTransform;

    //================================

	// Use this for initialization
	void OnEnable () {
		targetTransform = target.GetComponent<Transform>();
        thisTransform = gameObject.GetComponent<Transform>();
        LookAt2D(targetTransform);  //초기각도 = 대상을 바라보게끔
	}
	
	// Update is called once per frame
	void FixedUpdate () {
        
	}

    IEnumerator HomingMissile()
    {
        float targetAngle, deltaAngle;
        while(true)
        {
            if(homing)
            {
                targetAngle = Mathf.Atan2(targetTransform.position.y-thisTransform.position.y, targetTransform.position.x-thisTransform.position.x);
                deltaAngle = Mathf.Clamp(targetAngle, -MaxDeltaAngle, MaxDeltaAngle);
                thisTransform.Rotate(new Vector3(0,0,deltaAngle));
            }
            thisTransform.position += thisTransform.forward*speed;
            yield return 0;
        }
    }

    void LookAt2D(Transform target)
    {
        thisTransform.rotation = new Quaternion(0,0,Mathf.Atan2(target.position.y-thisTransform.position.y, target.position.x-thisTransform.position.x),0);
    }

}
