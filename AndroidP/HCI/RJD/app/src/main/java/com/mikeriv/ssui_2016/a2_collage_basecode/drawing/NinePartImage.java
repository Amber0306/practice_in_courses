package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.NinePatch;
import android.graphics.Paint;
import android.graphics.Rect;

/**
 * Created by dell on 2019/4/23.
 */

public class NinePartImage extends BaseVisualElement{

    private NinePatch mNinePatch;
    private Paint mPaint;
    private Rect mRect;

    public NinePartImage(float x, float y, float w, float h, NinePatch patches){
        this.mX=x;
        this.mY=y;
        this.mW=w;
        this.mH=h;
        this.mNinePatch=patches;
      //  mRect = new Rect((int)x, (int)y, (int)w, (int)h);
        //mRect = new Rect((int)x, (int)y, 90, 50);
    }

    @Override
    public void draw(Canvas onCanvas){
        mRect = new Rect((int)this.mX, (int)this.mY, (int)(this.getW()+this.mX),(int)(this.getH()+this.mY));
       // mRect = new Rect((int)this.mX, (int)this.mY, (int)(this.mNinePatch.getWidth()+this.mX),(int)(this.mNinePatch.getHeight()+this.mY));
        mPaint=new Paint();
        mPaint.setColor(Color.WHITE);
        onCanvas.save();
        mNinePatch.draw(onCanvas, mRect, mPaint);
        onCanvas.restore();
    }

}
