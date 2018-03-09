#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofBackground(239);
	ofSetWindowTitle("Insta");

	ofSetColor(39);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {
}

//--------------------------------------------------------------
void ofApp::draw() {

	int size = 60;

	for (int x = size / 2; x < ofGetWidth() + size / 2; x += size) {

		for (int y = size / 2; y < ofGetHeight() + size / 2; y += size) {

			ofPoint point = ofPoint(x, y);
			float radius = (size * 0.5) * 0.8;
			int type = ofNoise(x * 0.005, y * 0.005) * 11;
			this->draw_shape(point, radius , type);

			int n = ofNoise(x * 0.005, y * 0.005, ofGetFrameNum() * 0.01) * 12;
			for (int i = 0; i < n; i++) {
				
				float mini_radius = radius - 2.5 * i;
				if (mini_radius < 0) {

					break;
				}
				this->draw_shape(point, mini_radius, type);

			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw_shape(ofPoint point, float radius, int type) {

	int deg_span = 1;
	int rotate = 0;

	switch (type) {
	case 0:
	case 9:
		deg_span = 120;
		rotate = 270;
		break;
	case 1:
	case 8:
		deg_span = 90;
		rotate = 45;

		break;
	case 2:
	case 6:
		deg_span = 60;
		rotate = 30;
		break;
	case 3:
	case 4:
	case 5:
		deg_span = 1;
		break;
	case 10:
		deg_span = 30;
		break;
	}
	
	ofPushMatrix();
	ofTranslate(point);
	ofRotate(rotate);

	ofBeginShape();
	for (int deg = 0; deg < 360; deg += deg_span) {

		if (type == 10 && (deg / deg_span) % 2 == 0) {

			ofVertex(radius * 0.5 * cos(deg * DEG_TO_RAD), radius * 0.5 * sin(deg * DEG_TO_RAD));
		}
		else {

			ofVertex(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		}
	}
	ofEndShape(true);

	ofPopMatrix();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}