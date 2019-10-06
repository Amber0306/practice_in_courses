package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;



public class ColumnLayout extends BaseVisualElement {
    public ColumnLayout(float x, float y, float w, float h){
        this.mX=x;
        this.mY=y;
        this.mW=w;
        this.mH=h;
    }
    @Override
    public void doLayout(){
        float height=0;
        for(int i=0;i<this.mChildren.size();i++){
            this.mChildren.get(i).setPosition(this.mW/2-this.mChildren.get(i).getW()/2,height);
            height+=mChildren.get(i).getH();
        }
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#draw(android.graphics.Canvas)
     */
    @Override
    public void draw(Canvas onCanvas){
        onCanvas.save();
        onCanvas.clipRect(mX,mY,mX+mW,mY+mH);
        onCanvas.translate(mX,mY);
        for(int i=0;i<this.mChildren.size();i++){
            this.mChildren.get(i).draw(onCanvas);
        }
        onCanvas.restore();
    }
}
