package com.mikeriv.ssui_2016.puzzlegame;

import android.content.DialogInterface;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.ImageView;
import android.widget.Toast;

import com.mikeriv.ssui_2016.puzzlegame.model.PuzzleGameBoard;
import com.mikeriv.ssui_2016.puzzlegame.model.PuzzleGameState;
import com.mikeriv.ssui_2016.puzzlegame.model.PuzzleGameTile;
import com.mikeriv.ssui_2016.puzzlegame.util.PuzzleImageUtil;
import com.mikeriv.ssui_2016.puzzlegame.view.PuzzleGameTileView;

import java.util.Random;

public class PuzzleGameActivity extends AppCompatActivity {

    // The default grid size to use for the puzzle game 4 => 4x4 grid
    private static final int DEFAULT_PUZZLE_BOARD_SIZE = 3;

    // The id of the image to use for our puzzle game
    private static final int TILE_IMAGE_ID = R.drawable.kitty;

    //
    private static int mScore=0;

    /**
     * Button Listener that starts a new game - this must be attached to the new game button
     */
    private class mNewGameButtonOnClickListener implements View.OnClickListener{
        @Override
        public void onClick(View view) {
            // TODO start a new game if a new game button is clicked
            startNewGame();
        }
    };



    /**
     * Click Listener that Handles Tile Swapping when we click on a tile that is
     * neighboring the empty tile - this must be attached to every tileView in the grid
     */
    private class mGameTileOnClickListener implements View.OnClickListener {
        @Override
        public void onClick(View view) {
           // TODO handle swapping tiles and updating the tileViews if there is a valid swap
            // with an empty tile
            // If any changes happen, be sure to update the state of the game to check for a win
            // condition
        }
    };

    // Game State - what the game is currently doin
    private PuzzleGameState mGameState = PuzzleGameState.NONE;

    // The size of our puzzle board (mPuzzleBoardSize x mPuzzleBoardSize grid)
    private int mPuzzleBoardSize = DEFAULT_PUZZLE_BOARD_SIZE;

    // The puzzleboard model
    private PuzzleGameBoard mPuzzleGameBoard;

    // Views
    private TextView mScoreTextView;
    //
    private Button mNewGameButton;
    //
    private ImageView bodyImage;

    // The views for the puzzleboardtile models
    private PuzzleGameTileView[][] mPuzzleTileViews =
            new PuzzleGameTileView[mPuzzleBoardSize][mPuzzleBoardSize];


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_puzzle_game);

        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);


        // TODO initialize references to any containers views or layout groups etc.
        //TextView
        mScoreTextView = (TextView) findViewById(R.id.text_score);
        String str = getResources().getString(R.string.title_score_board);
        str = String.format(str, mScore);
        mScoreTextView.setText(str);

        //Button
        mNewGameButton=(Button)findViewById(R.id.btn_new);
        mNewGameButton.setOnClickListener( new mNewGameButtonOnClickListener());

        bodyImage=(ImageView)findViewById(R.id.image_body);
        //bodyImage.setImageBitmap(fullImageBitmap);
        //mPuzzleGameBoard=()

        // Initializes the game and updates the game state
        initGame();
        updateGameState();
    }

    /**
     * Creates the puzzleboard and the PuzzleGameTiles that serve as the model for the game. It
     * does image slicing to get the appropriate bitmap subdivisions of the TILE_IMAGE_ID. It
     * then creates a set for PuzzleGameTileViews that are used to display the information in models
     */
    private void initGame() {
        mPuzzleGameBoard = new PuzzleGameBoard(mPuzzleBoardSize, mPuzzleBoardSize);

        // Get the original image bitmap
        Bitmap fullImageBitmap = BitmapFactory.decodeResource(getResources(), TILE_IMAGE_ID);
        // Now scale the bitmap so it fits out screen dimensions and change aspect ratio (scale) to
        // fit a square
        int fullImageWidth = fullImageBitmap.getWidth();
        int fullImageHeight = fullImageBitmap.getHeight();
        int squareImageSize = (fullImageWidth > fullImageHeight) ? fullImageWidth : fullImageHeight;
        fullImageBitmap = Bitmap.createScaledBitmap(
                fullImageBitmap,
                squareImageSize,
                squareImageSize,
                false);

        // TODO calculate the appropriate size for each puzzle tile
        int tileImageSize=squareImageSize/mPuzzleBoardSize;

        // TODO create the PuzzleGameTiles for the PuzzleGameBoard using sections of the bitmap.
        // You may find PuzzleImageUtil helpful for getting sections of the bitmap
        // Also ensure the last tile (the bottom right tile) is set to be an "empty" tile
        // (i.e. not filled with an section of the original image)
        //bodyImage.setImageBitmap(fullImageBitmap);
        for(int i=0;i<mPuzzleBoardSize;i++)
        {
            for(int j=0;j<mPuzzleBoardSize;j++)
            {
                //row=i;col=j
                int index=i*mPuzzleBoardSize+j;
                Bitmap bitTile=PuzzleImageUtil.getSubdivisionOfBitmap(fullImageBitmap,
                        tileImageSize,tileImageSize,i,j);
                Drawable draw=new BitmapDrawable(bitTile);
                PuzzleGameTile mtile=new PuzzleGameTile(index,draw);
                //mtile.setOrderIndex(index);
                mPuzzleGameBoard.setTile(mtile,i,j);

                // TODO createPuzzleTileViews with the appropriate width, height
                int minwidth=mPuzzleGameBoard.getTile(i,j).getDrawable().getMinimumWidth();
                int minheight=mPuzzleGameBoard.getTile(i,j).getDrawable().getMinimumHeight();
                PuzzleGameTileView tv=createPuzzleTileViews(minwidth,minheight,index);
                tv.setImageBitmap(bitTile);
                tv.layout(tv.getLeft(),tv.getTop(),tv.getRight(),tv.getBottom());
            }
        }
       resetEmptyTileLocation();


        // createPuzzleTileViews(0, 0);
        /*
        int minisize=666777;
        for(int i=0;i<mPuzzleBoardSize-1;i++)
        {
            for(int j=0;j<mPuzzleBoardSize;j++)
            {
                int minwidth=mPuzzleGameBoard.getTile(i,j).getDrawable().getMinimumWidth();
                int minheight=mPuzzleGameBoard.getTile(i,j).getDrawable().getMinimumHeight();
                int id=mPuzzleGameBoard.getTile(i,j).getOrderIndex();
                PuzzleGameTileView tv=createPuzzleTileViews(minwidth,minheight,id);
                Bitmap bitTile=PuzzleImageUtil.getSubdivisionOfBitmap(fullImageBitmap,
                        tileImageSize,tileImageSize,i,j);
                tv.setImageBitmap(bitTile);
            }
        }
        */
    }

    /**
     * Creates a set of tile views based on the tileWidth and height
     * @param minTileViewWidth the minium width of the tile
     * @param minTileViewHeight the minimum height of the tile
     */

    private PuzzleGameTileView createPuzzleTileViews(int minTileViewWidth, int minTileViewHeight,int id) {
        int rowsCount = mPuzzleGameBoard.getRowsCount();
        int colsCount = mPuzzleGameBoard.getColumnsCount();
        // TODO Set up TileViews (that will be what the user interacts with)
        // Make sure each tileView gets a click listener for interaction
        // Be sure to set the appropriate LayoutParams so that your tileViews
        // So that they fit your gameboard properly
        for(int i=0;i<rowsCount;i++)
        {
            for(int j=0;j<colsCount;j++)
            {
                if(id==i*mPuzzleBoardSize+j)
                {
                    mPuzzleTileViews[i][j]=new PuzzleGameTileView(PuzzleGameActivity.this,
                            id,minTileViewWidth,minTileViewHeight);
                    //mPuzzleTileViews[i][j].setTileId(id);
                    mPuzzleTileViews[i][j].updateWithTile(mPuzzleGameBoard.getTile(i,j));
                    mPuzzleTileViews[i][j].setOnClickListener(new mGameTileOnClickListener());
                    return mPuzzleTileViews[i][j];
                }
            }
        }
        return null;
    }

    /**
     * Shuffles the puzzle tiles randomly such that tiles may only swap if they are swapping with
     * an empty tile to maintain solvability
     */
    private void shufflePuzzleTiles() {
        // TODO randomly shuffle the tiles such that tiles may only move spots if it is randomly
        // swapped with a neighboring empty tile

    }

    /**
     * Places the empty tile in the lower right corner of the grid
     */
    private void resetEmptyTileLocation() {
        // TODO
        mPuzzleGameBoard.getTile(mPuzzleBoardSize-1,mPuzzleBoardSize-1).setIsEmpty(true);
        mPuzzleGameBoard.getTile(mPuzzleBoardSize-1,mPuzzleBoardSize-1).setDrawable(null);
    }

    /**
     * Updates the game state by checking if the user has won. Also triggers the tileViews to update
     * their visuals based on the gameboard
     */
    private void updateGameState() {
        // TODO refresh tiles and handle winning the game and updating score
    }

    private void refreshGameBoardView() {
        // TODO update the PuzzleTileViews with the data stored in the PuzzleGameBoard
    }


    /**
     * Checks the game board to see if the tile indices are in proper increasing order
     * @return true if the tiles are in correct order and the game is won
     */
    private boolean hasWonGame() {
        // TODO check if the user has won the game
        return false;
    }

    /**
     * Updates the score displayed in the text view
     */
    private void updateScore() {
        // TODO update a score to be displayed to the user
        String str = getResources().getString(R.string.title_score_board);
        str = String.format(str, mScore);
        mScoreTextView.setText(str);
    }

    /**
     * Begins a new game by shuffling the puzzle tiles, changing the game state to playing
     * and showing a start message
     */
    private void startNewGame() {
        // TODO - handle starting a new game by shuffling the tiles and showing a start message,
        // and updating the game state

        AlertDialog.Builder dialog=new AlertDialog.Builder(PuzzleGameActivity.this);
        dialog.setTitle("Confirm:");
        dialog.setMessage("Start a new Game.");
        dialog.setCancelable(false);
        dialog.setPositiveButton("OK", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialogInterface, int i) {
                shufflePuzzleTiles();
                //updateGameState();
                mGameState=PuzzleGameState.PLAYING;
            }
        });
        dialog.setNegativeButton("Cancel", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialogInterface, int i) {
            }
        });
        dialog.show();
    }


}
