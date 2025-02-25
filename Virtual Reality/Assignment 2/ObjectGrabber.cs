using UnityEngine;

public class ObjectGrabber : MonoBehaviour
{
    private Camera mainCamera;
    private Outline outline;

    // Static reference to the currently grabbed object, allowing only one object is grabbed at a time.
    private static ObjectGrabber currentlyGrabbed = null;

    public float offsetDistanceFromCamera = 3f;

    void Start()
    {
        mainCamera = Camera.main;
        outline = GetComponent<Outline>();
    }

    void Update()
    {
        // When no object is currently grabbed.
        if (currentlyGrabbed == null)
        {
            // Ignore if the object is not highlighted.
            if (!outline.enabled)
                return;

            // Grab the object when the "A" button is pressed.
            if (Input.GetButtonDown("js8") || Input.GetButtonDown("js10"))
                Grab();

            return;
        }

        // When this object is currently grabbed.
        if (currentlyGrabbed == this)
        {
            // Continuously update the object's position to stay in front of the camera.
            UpdateGrabbedObjectPosition();

            // Drop the object when the "A" button is pressed again.
            if (Input.GetButtonDown("js8") || Input.GetButtonDown("js10"))
            {
                DropGrabbedObject();
            }
        }
    }

    void Grab()
    {
        currentlyGrabbed = this;
    }

    void DropGrabbedObject()
    {
        transform.position = new Vector3(
            transform.position.x,
            0.5f * transform.lossyScale.y,
            transform.position.z
        );

        currentlyGrabbed = null;
    }

    void UpdateGrabbedObjectPosition()
    {
        currentlyGrabbed.transform.position = mainCamera.transform.position
                                                + mainCamera.transform.forward * offsetDistanceFromCamera;
    }
}
