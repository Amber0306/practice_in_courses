package com.mikeriv.ssui_2016.puzzlegame;

import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.ColorDrawable;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.Toolbar;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RelativeLayout;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;
import android.widget.Toast;

import com.mikeriv.ssui_2016.puzzlegame.model.PuzzleGameBoard;
import com.mikeriv.ssui_2016.puzzlegame.model.PuzzleGameState;
import com.mikeriv.ssui_2016.puzzlegame.model.PuzzleGameTile;
import com.mikeriv.ssui_2016.puzzlegame.util.PuzzleImageUtil;
import com.mikeriv.ssui_2016.puzzlegame.view.PuzzleGameTileView;

import java.util.Random;

public class PuzzleGameActivity extends AppCompatActivity {

    // The default grid size to use for the puzzle game n => n*n grid
    private static final int DEFAULT_PUZZLE_BOARD_SIZE = 4;

    // The id of the image to use for our puzzle game
    private static final int TILE_IMAGE_ID = R.drawable.kitty;

    /**
     * Button Listener that starts a new game - this must be attached to the new game button
     */
    private final View.OnClickListener mNewGameButtonOnClickListener = new View.OnClickListener() {
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
    private final View.OnClickListener mGameTileOnClickListener = new View.OnClickListener() {
        @Override
        public void onClick(View view) {
            // TODO handle swapping tiles and updating the tileViews if there is a valid swap
            // with an empty tile
            // If any changes happen, be sure to update the state of the game to check for a win
            // condition
            PuzzleGameTileView v = (PuzzleGameTileView) view;
            int row = v.getTileId()/mPuzzleBoardSize;
            int col = v.getTileId()%mPuzzleBoardSize;
            if(mPuzzleGameBoard.isWithinBounds(row-1, col) && mPuzzleGameBoard.isEmptyTile(row-1, col)){
                PuzzleGameTileView v2 = mPuzzleTileViews[row-1][col];
                v2.updateWithTile(mPuzzleGameBoard.getTile(row, col));
                v.setImageDrawable(null);
                mPuzzleGameBoard.swapTiles(row, col, row-1, col);
            }else if(mPuzzleGameBoard.isWithinBounds(row+1, col) && mPuzzleGameBoard.isEmptyTile(row+1, col)){
                PuzzleGameTileView v2 = mPuzzleTileViews[row+1][col];
                v2.updateWithTile(mPuzzleGameBoard.getTile(row, col));
                v.setImageDrawable(null);
                mPuzzleGameBoard.swapTiles(row, col, row+1, col);
            }else if(mPuzzleGameBoard.isWithinBounds(row, col+1) && mPuzzleGameBoard.isEmptyTile(row, col+1)){
                PuzzleGameTileView v2 = mPuzzleTileViews[row][col+1];
                v2.setImageDrawable(mPuzzleGameBoard.getTile(row, col).getDrawable());
                v.setImageDrawable(null);
                mPuzzleGameBoard.swapTiles(row, col, row, col+1);
            }else if(mPuzzleGameBoard.isWithinBounds(row, col-1) && mPuzzleGameBoard.isEmptyTile(row, col-1)){
                PuzzleGameTileView v2 = mPuzzleTileViews[row][col-1];
                v2.updateWithTile(mPuzzleGameBoard.getTile(row, col));
                v.setImageDrawable(null);
                mPuzzleGameBoard.swapTiles(row, col, row, col-1);
            }
            updateScore();
            if(hasWonGame())
                mScoreTextView.setText("you won");
        }
    };

    // Game State - what the game is currently doing
    private PuzzleGameState mGameState = PuzzleGameState.NONE;

    // The size of our puzzle board (mPuzzleBoardSize x mPuzzleBoardSize grid)
    private int mPuzzleBoardSize = DEFAULT_PUZZLE_BOARD_SIZE;

    // The puzzle board model
    private PuzzleGameBoard mPuzzleGameBoard;

    // Views
    private TextView mScoreTextView;

    // The views for the puzzle board tile models
    private PuzzleGameTileView[][] mPuzzleTileViews =
            new PuzzleGameTileView[mPuzzleBoardSize][mPuzzleBoardSize];


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_puzzle_game);

        Toolbar toolbar = (Toolbar) findViewById(R.id.toolbar);
        setSupportActionBar(toolbar);

        mScoreTextView = (TextView) findViewById(R.id.text_score);

        // TODO initialize references to any containers views or layout groups etc.
        Button newGame = (Button) findViewById(R.id.btn_new_game);
        newGame.setOnClickListener(mNewGameButtonOnClickListener);

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

        // TODO calculate the appropriate size for each puzzle till
        // Calculate the with and height of the pieces
        int piecesWidth = fullImageWidth/mPuzzleBoardSize;
        int piecesHeight = fullImageHeight/mPuzzleBoardSize;

        // TODO create the PuzzleGameTiles for the PuzzleGameBoard using sections of the bitmap.
        // You may find PuzzleImageUtil helpful for getting sections of the bitmap
        // Also ensure the last tile (the bottom right tile) is set to be an "empty" tile
        // (i.e. not filled with an section of the original image)
        for(int i=0; i<mPuzzleBoardSize; ++i){
            for(int j=0; j<mPuzzleBoardSize; ++j){
                Bitmap tmp = PuzzleImageUtil.getSubdivisionOfBitmap(fullImageBitmap, piecesWidth,
                        piecesHeight, i, j);
                BitmapDrawable p = new BitmapDrawable(tmp);
                if(i == mPuzzleBoardSize-1 && j == mPuzzleBoardSize-1)
                    mPuzzleGameBoard.setTile(new PuzzleGameTile(i*mPuzzleBoardSize+j, null, true),i, j);
                else
                    mPuzzleGameBoard.setTile(new PuzzleGameTile(i*mPuzzleBoardSize+j, p), i, j);
            }
        }

        // TODO createPuzzleTileViews with the appropriate width, height
         createPuzzleTileViews(250, 250);
    }

        /**
         * Creates a set of tile views based on the tileWidth and height
         * @param minTileViewWidth the minium width of the tile
         * @param minTileViewHeight the minimum height of the tile
         */

    private void createPuzzleTileViews(int minTileViewWidth, int minTileViewHeight) {
        final int rowsCount = mPuzzleGameBoard.getRowsCount();
        final int colsCount = mPuzzleGameBoard.getColumnsCount();
        // TODO Set up TileViews (that will be what the user interacts with)
        // Make sure each tileView gets a click listener for interaction
        // Be sure to set the appropriate LayoutParams so that your tileViews
        // So that they fit your gameboard properly
        TableLayout tableLayout = (TableLayout) findViewById(R.id.tableLayout);
        for (int i = 0; i < rowsCount; ++i) {
            TableRow row = new TableRow(this);
            for (int j = 0; j < colsCount; ++j) {
                mPuzzleTileViews[i][j] = new PuzzleGameTileView(this, i * colsCount + j, minTileViewWidth, minTileViewHeight);
                mPuzzleTileViews[i][j].setImageDrawable(mPuzzleGameBoard.getTile(i, j).getDrawable());
                mPuzzleTileViews[i][j].setOnClickListener(mGameTileOnClickListener);
                row.addView(mPuzzleTileViews[i][j]);
            }
            tableLayout.addView(row);
        }
        boolean cbs=false;
        while(!cbs)
        {
            cbs=shufflePuzzleTiles();
        }
        updateScore();
    }

    /**
     * Shuffles the puzzle tiles
     */
    private boolean shufflePuzzleTiles() {
        // TODO randomly shuffle the tiles such that tiles may only move spots if it is randomly
        // swapped with a neighboring empty tile

        int[][] array=new int[][]{};
        if (mPuzzleBoardSize == 3) {
            int[][] array1 =
                    {
                            {0, 1, 2},
                            {3, 4, 5},
                            {6, 7, 8},
                    };
            array = array1;
        } else if (mPuzzleBoardSize == 4) {
            int[][] array2 =
                    {
                            {0, 1, 2, 3},
                            {4, 5, 6, 7},
                            {8, 9, 10, 11},
                            {12, 13, 14, 15}
                    };
            array = array2;
        }


        for (int i = 0; i < mPuzzleBoardSize; ++i) {
            for (int j = 0; j < mPuzzleBoardSize; ++j) {
                int i1 = (int) Math.floor(Math.random() * mPuzzleBoardSize);
                int j2 = (int) Math.floor(Math.random() * mPuzzleBoardSize);
                PuzzleGameTileView v1 = mPuzzleTileViews[i][j];
                PuzzleGameTileView v2 = mPuzzleTileViews[i1][j2];
                v1.updateWithTile(mPuzzleGameBoard.getTile(i1, j2));
                v2.updateWithTile(mPuzzleGameBoard.getTile(i, j));
                mPuzzleGameBoard.swapTiles(i, j, i1, j2);
                int temp = array[i][j];
                array[i][j] = array[i1][j2];
                array[i1][j2] = temp;
            }
        }
        int[] resultArray = new int[array.length * array.length];
        int index = 0;
        for (int ii = 0; ii < array.length; ii++) {
            for (int jj = 0; jj < array.length; jj++) {
                resultArray[index] = array[ii][jj];
                index++;
            }
        }
        boolean canBeSolved = false;
        int inversions = 0;
        for (int i = 0; i < resultArray.length; i++) {
            for (int j = i + 1; j < resultArray.length; j++) {
                if (resultArray[i] > resultArray[j]) {
                    inversions++;
                }
            }
        }

            if (inversions % 2 == 0) canBeSolved = true;

            if(!canBeSolved) return false;
            resetEmptyTileLocation();
            return true;

    }


    /**
     * Places the empty tile in the lower right corner of the grid
     */
    private void resetEmptyTileLocation() {
        // TODO
        for(int i=0; i<mPuzzleBoardSize; ++i){
            for(int j=0; j<mPuzzleBoardSize; ++j){
                if(mPuzzleGameBoard.isEmptyTile(i, j)){
                    mPuzzleTileViews[i][j].updateWithTile(mPuzzleGameBoard.getTile(mPuzzleBoardSize-1, mPuzzleBoardSize-1));
                    mPuzzleTileViews[mPuzzleBoardSize-1][mPuzzleBoardSize-1].updateWithTile(mPuzzleGameBoard.getTile(i, j));
                    mPuzzleGameBoard.swapTiles(i, j, mPuzzleBoardSize-1, mPuzzleBoardSize-1);
                    return;
                }
            }
        }
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
        if(mGameState == PuzzleGameState.WON)
            return true;
        return false;

    }

    /**
     * Updates the score displayed in the text view
     */
    private void updateScore() {
        // TODO update a score to be displayed to the user
        int score = 0;
        for(int i=0; i<mPuzzleGameBoard.getTotalTileCount(); i++)
            if(mPuzzleGameBoard.getTile(i/mPuzzleBoardSize, i%mPuzzleBoardSize).getOrderIndex() == i)
                ++score;
        mScoreTextView.setText("Score :" + String.valueOf(score));
        if(score ==  mPuzzleGameBoard.getTotalTileCount())
            mGameState = PuzzleGameState.WON;
        else
            mGameState = PuzzleGameState.PLAYING;
    }

    /**
     * Begins a new game by shuffling the puzzle tiles, changing the game state to playing
     * and showing a start message
     */
    private void startNewGame() {
        // TODO - handle starting a new game by shuffling the tiles and showing a start message,
        // and updating the game state
        boolean cbs=false;
        while(!cbs)
        {
            cbs=shufflePuzzleTiles();
        }
        updateGameState();
        updateScore();
        TextView textView = (TextView) findViewById(R.id.textGameStat);
        textView.setText(R.string.action_new_game);

    }


}
