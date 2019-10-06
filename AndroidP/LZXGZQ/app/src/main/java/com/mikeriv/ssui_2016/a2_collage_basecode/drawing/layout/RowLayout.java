package com.mikeriv.ssui_2016.a2_collage_basecode.drawing.layout;

import android.graphics.Canvas;

import com.mikeriv.ssui_2016.a2_collage_basecode.drawing.BaseVisualElement;

public class RowLayout extends BaseVisualElement {

    public RowLayout(float x, float y, float w, float h){
        this.x0=x;
        this.y0=y;
        this.w0=w;
        this.h0=h;
    }
    @Override
    public void doLayout(){
        float width=0;
        for(int i=0;i<this.children.size();i++){
            this.children.get(i).setPosition(width,this.h0/2-this.children.get(i).getH()/2);
            width+=children.get(i).getW();
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
