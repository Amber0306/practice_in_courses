package com.mikeriv.ssui_2016.a2_collage_basecode.drawing.clipping;

import android.graphics.Canvas;
import android.graphics.Path;
import android.graphics.RectF;
import android.graphics.Region;

import com.mikeriv.ssui_2016.a2_collage_basecode.drawing.BaseVisualElement;

public class OvalClip extends BaseVisualElement {

    public OvalClip(float x, float y, float w, float h){
        this.x0=x;
        this.y0=y;
        this.w0=w;
        this.h0=h;
    }

    @Override
    public void doLayout(){
        for(int i=0;i<this.children.size();i++){
            this.children.get(i).doLayout();
        }
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#draw(android.graphics.Canvas)
     */
    @Override
    public void draw(Canvas onCanvas){
        onCanvas.save();
        onCanvas.translate(x0,y0);
        RectF rectF=new RectF();
        rectF.left=0;
        rectF.top=0;
        rectF.right=this.w0;
        rectF.bottom=this.h0;
        Path path=new Path();
        onCanvas.clipPath(path);
        path.addOval(rectF,Path.Direction.CCW);
        onCanvas.clipPath(path, Region.Op.REPLACE);
        for(int i=0;i<this.children.size();i++){
            this.children.get(i).draw(onCanvas);
        }
        onCanvas.restore();
    }

}
