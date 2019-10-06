package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

public class RowLayout extends BaseVisualElement{
    public RowLayout(int a, int b, int c, int d){
        super(a, b, c, d);
    }

    @Override
    public void doLayout(){
        //TODO I do not know;
        float occupiedWidth = 0;
        for (VisualElement ChildView :
                childList) {
            ChildView.setPosition(occupiedWidth, (getH() - ChildView.getH())/ 2);
            occupiedWidth += ChildView.getW();
        }
        super.doLayout();
    }
}
