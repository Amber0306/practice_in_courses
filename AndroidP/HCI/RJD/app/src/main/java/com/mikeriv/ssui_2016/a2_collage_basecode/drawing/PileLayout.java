package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.support.v4.content.ContextCompat;



public class PileLayout extends BaseVisualElement{

    public PileLayout(float x, float y, float w, float h){
        this.mX=x;
        this.mY=y;
        this.mW=w;
        this.mH=h;
    }

    @Override
    public void doLayout(){
       for(int i=0;i<this.mChildren.size();i++){
            this.mChildren.get(i).setPosition(0,0);
        }
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#draw(android.graphics.Canvas)
     */
    @Override
    public void draw(Canvas onCanvas){
        onCanvas.save();
        onCanvas.clipRect(mX,mY,mX+mW,mY+mH);
        onCanvas.translate(mX,mY);
        for(int i=0;i<this.mChildren.size();i++){
            this.mChildren.get(i).draw(onCanvas);
        }
        onCanvas.restore();
    }
}
