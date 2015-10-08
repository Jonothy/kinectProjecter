#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxOpencv.h"
#include "ofxKinect.h"
#include "Clone.h"
#include "ofxFaceTracker.h"
#include "ofxFaceTrackerThreaded.h"

using namespace ofxCv;
using namespace cv;

#include "ofxFaceTracker.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();
    
        void drawPointCloud();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        void loadFace(string face);
		
        float get_real_xcoord(float frame_xcoord, float real_depth);
        float get_real_ycoord(float frame_ycoord, float real_depth);
    
        float left_pupil_xcoord;
        float left_pupil_ycoord;
        float left_pupil_depth;
    
        float right_pupil_xcoord;
        float right_pupil_ycoord;
        float right_pupil_depth;
    
        float left_eye_height;
        float right_eye_height;
        float pupil_distance;
    
        float bottom_face_coord_x;
        float bottom_face_coord_y;
    
        ofVec3f left_world_pos;
        ofVec3f right_world_pos;
    
        ofxKinect kinect;
        
        ofxCvColorImage colorImg;
        
        ofxCvGrayscaleImage grayImage; // grayscale depth image
        ofxCvGrayscaleImage grayThreshNear; // the near thresholded image
        ofxCvGrayscaleImage grayThreshFar; // the far thresholded image
        
        ofxCvContourFinder contourFinder;
        
        bool bThreshWithOpenCV;
        bool bDrawPointCloud;
        
        int nearThreshold;
        int farThreshold;
        
        int angle;
        
        // used for viewing the point cloud
        ofEasyCam easyCam;
    
        ofxFaceTrackerThreaded camTracker;
        
        ofxFaceTracker srcTracker;
        ofImage src;
        vector<ofVec2f> srcPoints;
        
        bool cloneReady;
        Clone clone;
        ofFbo srcFbo, maskFbo;
    
        ofDirectory faces;
        int currentFace;
};
