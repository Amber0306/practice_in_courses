package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

public class PileLayout extends BaseVisualElement{
    /*
    **Constructor
     */
    public PileLayout(int a, int b, int c, int d){
        super(a,b,c,d);
    }

    @Override
    public void doLayout(){
        for (VisualElement child:
                childList) {
            child.setPosition(0, 0);
        }
        super.doLayout();
    }
}
