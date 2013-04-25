//
//  Room.h
//  MAPSS
//
//  Created by Robert Hodgin on 01/01/12.
//
//  Edited by Tim Honeywell in Spring 2013
//


#pragma once
#include "cinder/gl/Vbo.h"

class Room {
public:
	Room();
	Room( const ci::Vec3f &dims, bool isPowerOn );
	void		init();
	void		updateTime();
	void		update();
	void		draw();
	
	void		setDims( const ci::Vec3f &dims ){ mDims = dims; };
	ci::Vec3f	getDims(){ return mDims; };
	ci::Vec3f	getRandCeilingPos();
	ci::Vec3f	getCornerCeilingPos();
	ci::Vec3f	getCornerFloorPos();
	ci::Vec3f	getLeftWallPos();
	float		getFloorLevel();
	
	void		adjustTimeMulti( float amt );
	float		getTimePer();
	float		getTimeDelta();
	bool		getTick();
	
	float		getPower(){			return mPower;					};
	bool		isPowerOn(){		return mIsPowerOn;				};
	
	float		getLightPower();
	
	ci::gl::VboMesh mVbo;
	
	// TIME
	float			mTime;				// Time elapsed in real world seconds
	float			mTimeElapsed;		// Time elapsed in simulation seconds
	float			mTimeMulti;			// Speed at which time passes
	float			mTimeAdjusted;		// Amount of time passed between last frame and current frame
	float			mTimer;				// A resetting counter for determining if a Tick has occured
	bool			mTick;				// Tick (aka step) for triggering discrete events
	
	// DIMENSIONS
	ci::Vec3f		mDims;				// Hesitant to rename this to 'bounds'. Might make it too easy to
	ci::Vec3f		mDimsDest;			// confuse with mRoomFbo.getBounds() which would return the Fbo Area.
	
	// POWER
	bool			mIsPowerOn;			// Power ranges from 0.0 to 1.0.
	float			mPower;
	
};