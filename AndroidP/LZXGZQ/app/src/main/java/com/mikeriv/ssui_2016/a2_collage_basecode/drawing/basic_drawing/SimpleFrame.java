package com.mikeriv.ssui_2016.a2_collage_basecode.drawing.basic_drawing;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

import com.mikeriv.ssui_2016.a2_collage_basecode.drawing.BaseVisualElement;

public class SimpleFrame extends BaseVisualElement {

    public SimpleFrame(float x, float y, float w, float h){
        this.x0=x;
        this.y0=y;
        this.w0=w;
        this.h0=h;
    }

    @Override
    public void draw(Canvas onCanvas){
        Paint paint =new Paint();
        paint.setColor(Color.BLACK);
        paint.setStrokeWidth(4.0f);
        onCanvas.save();
        onCanvas.clipRect(x0,y0,x0+w0,y0+h0);
        onCanvas.translate(x0,y0);
        onCanvas.drawLine(0,0,w0,0,paint);
        onCanvas.drawLine(w0,0,w0,h0,paint);
        onCanvas.drawLine(w0,h0,0,h0,paint);
        onCanvas.drawLine(0,h0,0,0,paint);
        onCanvas.restore();
    }
}
