package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;


public class CircleLayout extends BaseVisualElement {
    private float mLayoutCenterX;
    private float mLayoutCenterY;
    private float mLayoutRadius;
    public CircleLayout(float x, float y, float w, float h,float layoutCenterX, float layoutCenterY,float layoutRadius){
        this.mX=x;
        this.mY=y;
        this.mW=w;
        this.mH=h;
        this.mLayoutCenterX=layoutCenterX;
        this.mLayoutCenterY=layoutCenterY;
        this.mLayoutRadius=layoutRadius;
    }
    @Override
    public void doLayout(){
        double dangle=2*Math.PI/this.mChildren.size();
        double angle=0;
        for(int i=0;i<this.mChildren.size();i++){
            float x=(float)(mLayoutCenterX-mLayoutRadius*Math.cos(angle));
            float y=(float)(mLayoutCenterY-mLayoutRadius*Math.sin(angle));
            this.mChildren.get(i).setPosition(x-this.mChildren.get(i).getW()/2,y-this.mChildren.get(i).getH()/2);
            angle+=dangle;
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
