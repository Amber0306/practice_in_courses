package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;
import android.graphics.PointF;

import java.util.ArrayList;


/**
 * Created by dell on 2019/4/23.
 */

public class BaseVisualElement extends PrebaseVisualElement{
    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#setPosition(android.graphics.PointF)
     */

    protected float mX;
    protected float mY;
    protected float mW;
    protected float mH;
    protected VisualElement mParent;
    protected ArrayList<VisualElement> mChildren=new ArrayList<VisualElement>();


    @Override
    public void setPosition(PointF pos) {
        if (pos != null) {
            setPosition(pos.x, pos.y);
        }
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#setPosition(float, float)
     */
    @Override
    public void setPosition(float x, float y) {
        setX(x);
        setY(y);
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#setX(float)
     */
    @Override
    public void setX(float x){
        this.mX=x;
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#setY(float)
     */
    @Override
    public void setY(float y){
        this.mY=y;
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#getPosition()
     */
    @Override
    public PointF getPosition() {
        return new PointF(getX(),getY());
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#getX()
     */
    @Override
    public float getX(){
        return mX;
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#getY()
     */
    @Override
    public float getY(){
        return mY;
    }



    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#sizeIsIntrinsic()
     */
    @Override
    public boolean sizeIsIntrinsic() {
        // default value -- override in subclasses that need to...
        return false;
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#setSize(android.graphics.PointF)
     */
    @Override
    public void setSize(PointF size) {
        if (size != null) {
            setSize(size.x,size.y);
        }
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#setSize(float, float)
     */
    @Override
    public void setSize(float w, float h) {
        setW(w);
        setH(h);
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#setW(float)
     */
    @Override
    public void setW(float w){
        this.mW=w;

    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#setH(float)
     */
    @Override
     public void setH(float h){
        this.mH=h;
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#getSize()
     */
    @Override
    public PointF getSize() {
        return new PointF(getW(),getH());
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#getW()
     */
    @Override
     public float getW(){
        return this.mW;
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#getH()
     */
    @Override
     public float getH(){
        return this.mH;
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#getParent()
     */
    @Override
     public VisualElement getParent(){
        return null;
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#setParent()
     */
    @Override
     public void setParent(VisualElement newParent){
        this.mParent=newParent;
    }



    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#getNumChildren()
     */
    @Override
    public int getNumChildren(){
        return this.mChildren.size();
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#getChildAt(int)
     */
    @Override
    public VisualElement getChildAt(int index){
            if(mChildren!=null&&index<mChildren.size()&&index>=0)
                return this.mChildren.get(index);
            else
                return null;
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#findChild(com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement)
     */
    @Override
   public int findChild(VisualElement child){
        if(mChildren!=null&&child!=null&&mChildren.contains(child))
            return this.mChildren.indexOf(child);
        else
            return -1;
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#addChild(com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement)
     */
    @Override
   public void addChild(VisualElement child){
        if(child!=null&&mChildren!=null)
        this.mChildren.add(child);
    }


    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#removeChildAt(int)
     */
    @Override
    public void removeChildAt(int index){
        this.mChildren.remove(index);
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#removeChild(com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement)
     */
    @Override
    public void removeChild(VisualElement child){
        if(child!=null)
        this.mChildren.remove(this.findChild(child));
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#moveChildFirst(com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement)
     */
    @Override
    public void moveChildFirst(VisualElement child){
        if(child!=null&&mChildren!=null&&this.mChildren.contains(child)) {
                mChildren.remove(child);
                mChildren.add(0, child);
        }

    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#moveChildLast(com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement)
     */
    @Override
    public void moveChildLast(VisualElement child){
        if(child!=null&&mChildren!=null&&this.mChildren.contains(child)) {
                mChildren.remove(child);
                mChildren.add(mChildren.size() - 1, child);
        }
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#moveChildEarlier(com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement)
     */
    @Override
     public void moveChildEarlier(VisualElement child){
        if(child!=null&&mChildren!=null&&this.mChildren.contains(child)){
                int index;
                if((index=this.findChild(child))!=0){
                    mChildren.remove(child);
                    mChildren.add(index-1,child);
                }
        }
    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#moveChildLater(com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement)
     */
    @Override
     public void moveChildLater(VisualElement child){
        if(child!=null&&mChildren!=null&&this.mChildren.contains(child)) {
                int index;
                if ((index = this.findChild(child)) != mChildren.size() - 1) {
                    mChildren.remove(child);
                    mChildren.add(index + 1, child);
                }
        }
    }


    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#doLayout()
     */
    @Override
    public void doLayout(){

    }

    /* (non-Javadoc)
     * @see com.mikeriv.ssui_2016.a2_collage_basecode.drawing.VisualElement#draw(android.graphics.Canvas)
     */
    @Override
   public void draw(Canvas onCanvas){

    }

}
