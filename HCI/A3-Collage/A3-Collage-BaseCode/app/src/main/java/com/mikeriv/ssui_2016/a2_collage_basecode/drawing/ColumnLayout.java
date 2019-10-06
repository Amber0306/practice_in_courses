package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

public class ColumnLayout extends BaseVisualElement {

    public ColumnLayout(float a, float b, float c, float d){
        super(a,b,c,d);
    }

    @Override
    public void doLayout(){
        float occupiedHeight = 0;
        for (VisualElement ChildView :
                childList) {
            ChildView.setPosition((getW()- ChildView.getW() )/ 2, occupiedHeight);
            occupiedHeight += ChildView.getH();
        }
        super.doLayout();
    }
}
