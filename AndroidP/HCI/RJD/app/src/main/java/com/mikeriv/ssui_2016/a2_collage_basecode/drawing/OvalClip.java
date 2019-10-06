package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Path;
import android.graphics.RectF;
import android.graphics.Region;

/**
 * Created by dell on 2019/4/23.
 */

public class OvalClip extends BaseVisualElement{
    public OvalClip(float x, float y, float w, float h){
        this.mX=x;
        this.mY=y;
        this.mW=w;
        this.mH=h;
    }

    @Override
    public void doLayout(){
        for(int i=0;i<this.mChildren.size();i++){
            this.mChildren.get(i).doLayout();
        }
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#draw(android.graphics.Canvas)
     */
    @Override
    public void draw(Canvas onCanvas){
        onCanvas.save();
        onCanvas.translate(mX,mY);
        RectF oval=new RectF();
        oval.left=0;
        oval.top=0;
        oval.right=this.mW;
        oval.bottom=this.mH;
        Path mPath=new Path();
        //mPath.reset();
        onCanvas.clipPath(mPath); // makes the clip empty
        mPath.addOval(oval,Path.Direction.CCW);
        onCanvas.clipPath(mPath, Region.Op.REPLACE);
        for(int i=0;i<this.mChildren.size();i++){
            this.mChildren.get(i).draw(onCanvas);
        }
        onCanvas.restore();
    }


}
