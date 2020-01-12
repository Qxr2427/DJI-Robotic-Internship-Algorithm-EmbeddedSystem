// Auto-generated. Do not edit!

// (in-package simple_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let RegionOccupy = require('./RegionOccupy.js');
let CastleEnergy = require('./CastleEnergy.js');

//-----------------------------------------------------------

class GameStatus {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.region_occupy = null;
      this.castle_energy = null;
      this.red_position = null;
      this.blue_position = null;
      this.red_step_move = null;
      this.blue_step_move = null;
      this.red_score = null;
      this.blue_score = null;
      this.round_remain_tick = null;
      this.round_remain_cnt = null;
      this.round_team = null;
    }
    else {
      if (initObj.hasOwnProperty('region_occupy')) {
        this.region_occupy = initObj.region_occupy
      }
      else {
        this.region_occupy = [];
      }
      if (initObj.hasOwnProperty('castle_energy')) {
        this.castle_energy = initObj.castle_energy
      }
      else {
        this.castle_energy = [];
      }
      if (initObj.hasOwnProperty('red_position')) {
        this.red_position = initObj.red_position
      }
      else {
        this.red_position = 0;
      }
      if (initObj.hasOwnProperty('blue_position')) {
        this.blue_position = initObj.blue_position
      }
      else {
        this.blue_position = 0;
      }
      if (initObj.hasOwnProperty('red_step_move')) {
        this.red_step_move = initObj.red_step_move
      }
      else {
        this.red_step_move = 0;
      }
      if (initObj.hasOwnProperty('blue_step_move')) {
        this.blue_step_move = initObj.blue_step_move
      }
      else {
        this.blue_step_move = 0;
      }
      if (initObj.hasOwnProperty('red_score')) {
        this.red_score = initObj.red_score
      }
      else {
        this.red_score = 0;
      }
      if (initObj.hasOwnProperty('blue_score')) {
        this.blue_score = initObj.blue_score
      }
      else {
        this.blue_score = 0;
      }
      if (initObj.hasOwnProperty('round_remain_tick')) {
        this.round_remain_tick = initObj.round_remain_tick
      }
      else {
        this.round_remain_tick = 0;
      }
      if (initObj.hasOwnProperty('round_remain_cnt')) {
        this.round_remain_cnt = initObj.round_remain_cnt
      }
      else {
        this.round_remain_cnt = 0;
      }
      if (initObj.hasOwnProperty('round_team')) {
        this.round_team = initObj.round_team
      }
      else {
        this.round_team = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GameStatus
    // Serialize message field [region_occupy]
    // Serialize the length for message field [region_occupy]
    bufferOffset = _serializer.uint32(obj.region_occupy.length, buffer, bufferOffset);
    obj.region_occupy.forEach((val) => {
      bufferOffset = RegionOccupy.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [castle_energy]
    // Serialize the length for message field [castle_energy]
    bufferOffset = _serializer.uint32(obj.castle_energy.length, buffer, bufferOffset);
    obj.castle_energy.forEach((val) => {
      bufferOffset = CastleEnergy.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [red_position]
    bufferOffset = _serializer.uint8(obj.red_position, buffer, bufferOffset);
    // Serialize message field [blue_position]
    bufferOffset = _serializer.uint8(obj.blue_position, buffer, bufferOffset);
    // Serialize message field [red_step_move]
    bufferOffset = _serializer.uint8(obj.red_step_move, buffer, bufferOffset);
    // Serialize message field [blue_step_move]
    bufferOffset = _serializer.uint8(obj.blue_step_move, buffer, bufferOffset);
    // Serialize message field [red_score]
    bufferOffset = _serializer.int16(obj.red_score, buffer, bufferOffset);
    // Serialize message field [blue_score]
    bufferOffset = _serializer.int16(obj.blue_score, buffer, bufferOffset);
    // Serialize message field [round_remain_tick]
    bufferOffset = _serializer.uint8(obj.round_remain_tick, buffer, bufferOffset);
    // Serialize message field [round_remain_cnt]
    bufferOffset = _serializer.uint8(obj.round_remain_cnt, buffer, bufferOffset);
    // Serialize message field [round_team]
    bufferOffset = _serializer.uint8(obj.round_team, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GameStatus
    let len;
    let data = new GameStatus(null);
    // Deserialize message field [region_occupy]
    // Deserialize array length for message field [region_occupy]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.region_occupy = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.region_occupy[i] = RegionOccupy.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [castle_energy]
    // Deserialize array length for message field [castle_energy]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.castle_energy = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.castle_energy[i] = CastleEnergy.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [red_position]
    data.red_position = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [blue_position]
    data.blue_position = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [red_step_move]
    data.red_step_move = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [blue_step_move]
    data.blue_step_move = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [red_score]
    data.red_score = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [blue_score]
    data.blue_score = _deserializer.int16(buffer, bufferOffset);
    // Deserialize message field [round_remain_tick]
    data.round_remain_tick = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [round_remain_cnt]
    data.round_remain_cnt = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [round_team]
    data.round_team = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 2 * object.region_occupy.length;
    length += 2 * object.castle_energy.length;
    return length + 19;
  }

  static datatype() {
    // Returns string type for a message object
    return 'simple_msgs/GameStatus';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '3c1a9bf389a73be248100bdba5d1e8fd';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    RegionOccupy[] region_occupy
    CastleEnergy[] castle_energy
    uint8 red_position
    uint8 blue_position
    uint8 red_step_move
    uint8 blue_step_move
    int16 red_score
    int16 blue_score
    uint8 round_remain_tick
    uint8 round_remain_cnt
    uint8 round_team
    
    ================================================================================
    MSG: simple_msgs/RegionOccupy
    uint8 status
    uint8 belong
    
    ================================================================================
    MSG: simple_msgs/CastleEnergy
    uint8 red_energy
    uint8 blue_energy
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GameStatus(null);
    if (msg.region_occupy !== undefined) {
      resolved.region_occupy = new Array(msg.region_occupy.length);
      for (let i = 0; i < resolved.region_occupy.length; ++i) {
        resolved.region_occupy[i] = RegionOccupy.Resolve(msg.region_occupy[i]);
      }
    }
    else {
      resolved.region_occupy = []
    }

    if (msg.castle_energy !== undefined) {
      resolved.castle_energy = new Array(msg.castle_energy.length);
      for (let i = 0; i < resolved.castle_energy.length; ++i) {
        resolved.castle_energy[i] = CastleEnergy.Resolve(msg.castle_energy[i]);
      }
    }
    else {
      resolved.castle_energy = []
    }

    if (msg.red_position !== undefined) {
      resolved.red_position = msg.red_position;
    }
    else {
      resolved.red_position = 0
    }

    if (msg.blue_position !== undefined) {
      resolved.blue_position = msg.blue_position;
    }
    else {
      resolved.blue_position = 0
    }

    if (msg.red_step_move !== undefined) {
      resolved.red_step_move = msg.red_step_move;
    }
    else {
      resolved.red_step_move = 0
    }

    if (msg.blue_step_move !== undefined) {
      resolved.blue_step_move = msg.blue_step_move;
    }
    else {
      resolved.blue_step_move = 0
    }

    if (msg.red_score !== undefined) {
      resolved.red_score = msg.red_score;
    }
    else {
      resolved.red_score = 0
    }

    if (msg.blue_score !== undefined) {
      resolved.blue_score = msg.blue_score;
    }
    else {
      resolved.blue_score = 0
    }

    if (msg.round_remain_tick !== undefined) {
      resolved.round_remain_tick = msg.round_remain_tick;
    }
    else {
      resolved.round_remain_tick = 0
    }

    if (msg.round_remain_cnt !== undefined) {
      resolved.round_remain_cnt = msg.round_remain_cnt;
    }
    else {
      resolved.round_remain_cnt = 0
    }

    if (msg.round_team !== undefined) {
      resolved.round_team = msg.round_team;
    }
    else {
      resolved.round_team = 0
    }

    return resolved;
    }
};

module.exports = GameStatus;
