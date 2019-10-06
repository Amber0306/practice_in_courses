package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;

public class CircleLayout extends BaseVisualElement {
    private float CenterX;
    private float CenterY;
    private float Radius;
    public CircleLayout(float xLoc, float yLoc, float width, float height, float CenterX,
                        float CenterY, float Radius) {
        super(xLoc, yLoc, width, height);
        this.CenterX = CenterX;
        this.CenterY = CenterY;
        this.Radius = Radius;
    }

    @Override
    public void doLayout() {
        double equalAngle = 2 * Math.PI / getNumChildren();
        int i=0;
        while (i < getNumChildren()) {
            VisualElement ve = getChildAt(i);
            ve.setX(CenterX + (float)(Radius * Math.sin(equalAngle * i)) - ve.getW() / 2);
            ve.setY(CenterY - (float)(Radius * Math.cos(equalAngle * i)) - ve.getH() / 2);
            i++;
        }
        super.doLayout();
    }
    @Override
    public void draw(Canvas onCanvas) {
        Paint paint = new Paint();
        paint.setColor(Color.BLUE);
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(5);
        onCanvas.drawCircle(CenterX, CenterY, Radius, paint);
        super.draw(onCanvas);
    }
}
