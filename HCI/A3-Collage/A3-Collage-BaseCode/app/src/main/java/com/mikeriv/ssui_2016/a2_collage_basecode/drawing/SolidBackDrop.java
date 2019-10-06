package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.RectF;

public class SolidBackDrop extends BaseVisualElement {

    private int color;

   @Override
   public void draw(Canvas onCanvas){
       RectF rect = new RectF(0, 0, getW(), getH());
       Paint paint = new Paint();
       paint.setColor(color);
       onCanvas.drawRect(rect, paint);
       super.draw(onCanvas);
   }

    /*
    **Constructors
     */
    public SolidBackDrop(float x, float y, float w, float h, int color){
        super(x, y, w, h);
        this.color = color;
    }

}
