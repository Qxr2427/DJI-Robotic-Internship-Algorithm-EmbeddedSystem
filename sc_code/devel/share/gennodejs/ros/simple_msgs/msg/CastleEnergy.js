// Auto-generated. Do not edit!

// (in-package simple_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class CastleEnergy {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.red_energy = null;
      this.blue_energy = null;
    }
    else {
      if (initObj.hasOwnProperty('red_energy')) {
        this.red_energy = initObj.red_energy
      }
      else {
        this.red_energy = 0;
      }
      if (initObj.hasOwnProperty('blue_energy')) {
        this.blue_energy = initObj.blue_energy
      }
      else {
        this.blue_energy = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type CastleEnergy
    // Serialize message field [red_energy]
    bufferOffset = _serializer.uint8(obj.red_energy, buffer, bufferOffset);
    // Serialize message field [blue_energy]
    bufferOffset = _serializer.uint8(obj.blue_energy, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type CastleEnergy
    let len;
    let data = new CastleEnergy(null);
    // Deserialize message field [red_energy]
    data.red_energy = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [blue_energy]
    data.blue_energy = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a message object
    return 'simple_msgs/CastleEnergy';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '9299551f2d90f96de59e7c55bb10e426';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 red_energy
    uint8 blue_energy
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new CastleEnergy(null);
    if (msg.red_energy !== undefined) {
      resolved.red_energy = msg.red_energy;
    }
    else {
      resolved.red_energy = 0
    }

    if (msg.blue_energy !== undefined) {
      resolved.blue_energy = msg.blue_energy;
    }
    else {
      resolved.blue_energy = 0
    }

    return resolved;
    }
};

module.exports = CastleEnergy;
