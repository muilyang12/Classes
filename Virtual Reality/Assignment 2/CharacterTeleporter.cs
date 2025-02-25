using UnityEngine;

public class CharacterTeleporter : MonoBehaviour
{
    private Camera mainCamera;

    [SerializeField] private Transform ground;
    private CharacterController characterController;

    public float maxDistance = 50f;

    void Start()
    {
        mainCamera = Camera.main;
        characterController = GetComponent<CharacterController>();
    }

    void Update()
    {
        // Check if the teleport button ("Y") is pressed on VR controller.
        if (Input.GetButtonDown("js0") || Input.GetButtonDown("js3"))
        {
            // Create a ray starting from the camera position, pointing forward.
            Ray ray = new Ray(mainCamera.transform.position, mainCamera.transform.forward);
            RaycastHit hit;

            // Perform raycast to check if the ray hits an object within maxDistance.
            if (Physics.Raycast(ray, out hit, maxDistance))
            {
                // Check if the object hit by the raycast is the specified ground object.
                if (hit.collider.transform == ground)
                {
                    // Calculate horizontal movement vector and move the character instantly.
                    Vector3 movement = new Vector3(hit.point.x - transform.position.x, 0, hit.point.z - transform.position.z);
                    characterController.Move(movement);
                }
            }
        }

    }
}
