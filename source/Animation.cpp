#include "Animation.h"

Animation::Animation(std::shared_ptr<Actor> owner) : Component(owner) {
    current_animation_ = nullptr;
}
Animation::~Animation() {
    ;
}

void Animation::Update(float32 delta_time) {
    frame_time_ += delta_time;
    if(frame_time_ >= .07) {
        frame_time_ = 0;
        current_frame_++;
        if(current_animation_ != nullptr && current_frame_ >= current_animation_->size()) {
            current_frame_ = 0;
        }
        owner_->SetSpriteClip(current_animation_->at(current_frame_));
    }
    CopyEventState();
    UpdateState();
    if(!EventStateIsCurrent()) {
        ChooseAnimation();
    }
}

void Animation::Initialize() {
    state_[kFacingLeft] = false;
    state_[kFacingRight] = false;
    state_[kMoving] = false;
    state_[kJumping] = false;

    last_state_[kFacingLeft] = false;
    last_state_[kFacingRight] = false;
    last_state_[kMoving] = false;
    last_state_[kJumping] = false;

    SetAnimation("face-screen");
}

void Animation::AddAnimation(std::string name, std::vector<SDL_Rect>* animation) {
    animations_[name] = animation;
}

void Animation::UpdateState() {
    if(owner_->CheckEvent(MOVE_LEFT)) {
        state_.at(kMoving) = true;
        state_.at(kFacingLeft) = true;
    }
    if(owner_->CheckEvent(MOVE_RIGHT)) {
        state_.at(kMoving) = true;
        state_.at(kFacingRight) = true;
    }
    if(!owner_->CheckEvent(MOVE_LEFT) && !owner_->CheckEvent(MOVE_RIGHT)) {
        state_.at(kMoving) = false;
    }
    // if(owner_->CheckEvent(MOVE_DOWN)) {
    //     ;
    // }
}

void Animation::ChooseAnimation() {
    if(state_.at(kMoving) && state_.at(kFacingLeft)) {
        SetAnimation("run-left");
    }
    if(state_.at(kMoving) && state_.at(kFacingRight)) {
        SetAnimation("run-right");
    }
    if(!state_.at(kMoving) && state_.at(kFacingLeft)) {
        SetAnimation("standing-left");
    }
    if(!state_.at(kMoving) && state_.at(kFacingRight)) {
        SetAnimation("standing-right");
    }
}

void Animation::SetAnimation(std::string name) {
    frame_time_ = 0;
    current_animation_ = animations_.at(name);
}

bool Animation::EventStateIsCurrent() {
    State temp;
    for(auto iter = state_.begin(); iter != state_.end(); ++iter) {
        temp = iter->first;
        if(state_.at(temp) != last_state_.at(temp)) {
            return false;
        }
    }

    return true;
}

void Animation::CopyEventState() {
    State temp;
    for(auto iter = state_.begin(); iter != state_.end(); ++iter) {
        temp = iter->first;
        last_state_.at(temp) = state_.at(temp);
    }
}
