package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

/**
 * Created by dell on 2019/4/23.
 */

public class SimpleFrame extends BaseVisualElement{
    public SimpleFrame(float x, float y, float w, float h){
        this.mX=x;
        this.mY=y;
        this.mW=w;
        this.mH=h;
    }

    @Override
    public void draw(Canvas onCanvas){
        Paint mPaint =new Paint();
        mPaint.setColor(Color.BLACK);
        mPaint.setStrokeWidth(4.0f);
//      mPaint.setAntiAlias(false);
        onCanvas.save();
        onCanvas.clipRect(mX,mY,mX+mW,mY+mH);
        onCanvas.translate(mX,mY);
        onCanvas.drawLine(0,0,mW,0,mPaint);
        onCanvas.drawLine(mW,0,mW,mH,mPaint);
        onCanvas.drawLine(mW,mH,0,mH,mPaint);
        onCanvas.drawLine(0,mH,0,0,mPaint);
        onCanvas.restore();
    }
}
