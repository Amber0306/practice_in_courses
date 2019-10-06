package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;
import android.graphics.Paint;

/**
 * Created by dell on 2019/4/23.
 */

public class SolidBackDrop extends BaseVisualElement{
    private int mColor;
    public Paint mPaint;
    public SolidBackDrop(float x, float y, float w, float h, int color){
        this.mX=x;
        this.mY=y;
        this.mW=w;
        this.mH=h;
        mColor=color;
        mPaint=new Paint();
        mPaint.setColor(mColor);
    }

    @Override
    public void doLayout(){
        for(int i=0;i<this.mChildren.size();i++){
            this.mChildren.get(i).doLayout();
        }
    }
    @Override
    public void draw(Canvas onCanvas){
        onCanvas.save();
        onCanvas.clipRect(mX,mY,mX+mW,mY+mH);
        onCanvas.translate(mX,mY);
        onCanvas.drawRect(0, 0, mW, mH, mPaint);
        for(int i=0;i<this.mChildren.size();i++){
            this.mChildren.get(i).draw(onCanvas);
        }
        onCanvas.restore();
    }

}
