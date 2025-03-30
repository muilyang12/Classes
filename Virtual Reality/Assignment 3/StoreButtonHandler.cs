using UnityEngine;

public class StoreButtonHandler : MonoBehaviour
{
    public ObjectMenuController menuController;
    public GameObject storeButton;
    public InventoryController inventoryController;

    private bool isHovered = false;

    void Start()
    {
        RaycastManager.RegisterRaycastHitEvent(HandleRaycastHit);
    }

    void OnDestroy()
    {
        RaycastManager.UnregisterRaycastHitEvent(HandleRaycastHit);
    }

    private void HandleRaycastHit(RaycastHit? hit)
    {
        if (hit.HasValue && hit.Value.collider.gameObject == storeButton)
            isHovered = true;
        else
            isHovered = false;
    }

    void Update()
    {
        // Button "B"
        if (Input.GetButtonDown("js8") || Input.GetButtonDown("js10") || Input.GetKeyDown(KeyCode.B))
        {
            if (!isHovered)
                return;

            if (menuController.GetMenuTargetObject() != null)
            {
                Store();

                menuController.Toggle();
            }
        }
    }

    void Store()
    {
        GameObject menuTargetObject = menuController.GetMenuTargetObject();

        bool success = inventoryController.AddItem(menuTargetObject);

        if (!success)
        {
            Debug.Log("Full !!");

            return;
        }

        menuTargetObject.SetActive(false);
    }
}
