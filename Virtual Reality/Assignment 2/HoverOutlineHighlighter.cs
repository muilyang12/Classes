using UnityEngine;
using UnityEngine.EventSystems;

public class HoverOutlineHighlighter : MonoBehaviour, IPointerEnterHandler, IPointerExitHandler
{
    private Outline outline;

    void Start()
    {
        outline = GetComponent<Outline>();
        
        outline.OutlineColor = Color.red;
        outline.OutlineWidth = 3;
        outline.enabled = false;
    }

    void Update()
    {

    }

    public void OnPointerEnter(PointerEventData eventData)
    {
        if (outline != null)
            outline.enabled = true;
    }

    public void OnPointerExit(PointerEventData eventData)
    {
        if (outline != null)
            outline.enabled = false;
    }
}
