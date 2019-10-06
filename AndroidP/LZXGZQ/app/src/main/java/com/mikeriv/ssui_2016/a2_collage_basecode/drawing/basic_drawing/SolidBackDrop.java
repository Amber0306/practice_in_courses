package com.mikeriv.ssui_2016.a2_collage_basecode.drawing.basic_drawing;

import android.graphics.Canvas;
import android.graphics.Paint;

import com.mikeriv.ssui_2016.a2_collage_basecode.drawing.BaseVisualElement;

public class SolidBackDrop extends BaseVisualElement {
    private int Color;
    public Paint paint;
    public SolidBackDrop(float x, float y, float w, float h, int color){
        this.x0=x;
        this.y0=y;
        this.w0=w;
        this.h0=h;
        Color=color;
        paint=new Paint();
        paint.setColor(Color);
    }

    @Override
    public void doLayout(){
        for(int i=0;i<this.children.size();i++){
            this.children.get(i).doLayout();
        }
    }
    @Override
    public void draw(Canvas onCanvas){
        onCanvas.save();
        onCanvas.clipRect(x0,y0,x0+w0,y0+h0);
        onCanvas.translate(x0,y0);
        onCanvas.drawRect(0, 0, w0, h0, paint);
        for(int i=0;i<this.children.size();i++){
            this.children.get(i).draw(onCanvas);
        }
        onCanvas.restore();
    }

}
