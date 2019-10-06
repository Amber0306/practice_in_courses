package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.RectF;

public class SimpleFrame extends BaseVisualElement {
    /*
    **Constructors
     */

    public SimpleFrame(int x, int y, int w, int h){
        super(x, y, w, h);
    }

    @Override
    public void draw(Canvas onCanvas){
        RectF rect = new RectF(getX()-getW()/2, getY()+getH()/2,
                getX()+getW()/2, getY()-getH()/2);
        Paint paint_black = new Paint();
        paint_black.setColor(Color.BLACK);
        paint_black.setStyle(Paint.Style.STROKE);
        paint_black.setStrokeWidth(1);
        onCanvas.drawRect(rect, paint_black);
    }
}
