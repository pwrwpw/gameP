using UnityEngine;

public class PlayerMovement : MonoBehaviour
{
	public float force = 200f;
	private void FixedUpdate()
	{
		Rigidbody player;
		player = GetComponent<Rigidbody>();

		if (Input.GetKey(KeyCode.D) || Input.GetKey(KeyCode.RightArrow))
		{
			player.AddForce(force * Time.deltaTime, 0f, 0f, ForceMode.VelocityChange);	
		}

		else if (Input.GetKey(KeyCode.A) || Input.GetKey(KeyCode.LeftArrow))
		{
			player.AddForce(-force * Time.deltaTime, 0f, 0f, ForceMode.VelocityChange);
		}
	}
}
