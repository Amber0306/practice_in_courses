package com.mikeriv.ssui_2016.a2_collage_basecode.drawing.layout;

import android.graphics.Canvas;

import com.mikeriv.ssui_2016.a2_collage_basecode.drawing.BaseVisualElement;

public class CircleLayout extends BaseVisualElement {
    private float LayoutCenterX;
    private float LayoutCenterY;
    private float LayoutRadius;
    public CircleLayout(float x, float y, float w, float h,float layoutCenterX, float layoutCenterY,float layoutRadius){
        this.x0=x;
        this.y0=y;
        this.w0=w;
        this.h0=h;
        this.LayoutCenterX=layoutCenterX;
        this.LayoutCenterY=layoutCenterY;
        this.LayoutRadius=layoutRadius;
    }
    @Override
    public void doLayout(){
        double angle0=2*Math.PI/this.children.size();
        double angle1=0;
        for(int i=0;i<this.children.size();i++){
            float x=(float)(LayoutCenterX-LayoutRadius*Math.cos(angle1));
            float y=(float)(LayoutCenterY-LayoutRadius*Math.sin(angle1));
            this.children.get(i).setPosition(x-this.children.get(i).getW()/2,y-this.children.get(i).getH()/2);
            angle1+=angle0;
        }
    }


    @Override
    public void draw(Canvas onCanvas){
        onCanvas.save();
        onCanvas.clipRect(x0,y0,x0+w0,y0+h0);
        onCanvas.translate(x0,y0);
        for(int i=0;i<this.children.size();i++){
            this.children.get(i).draw(onCanvas);
        }
        onCanvas.restore();
    }
}
