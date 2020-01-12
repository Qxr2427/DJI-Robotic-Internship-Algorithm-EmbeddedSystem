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

class RegionOccupy {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.status = null;
      this.belong = null;
    }
    else {
      if (initObj.hasOwnProperty('status')) {
        this.status = initObj.status
      }
      else {
        this.status = 0;
      }
      if (initObj.hasOwnProperty('belong')) {
        this.belong = initObj.belong
      }
      else {
        this.belong = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RegionOccupy
    // Serialize message field [status]
    bufferOffset = _serializer.uint8(obj.status, buffer, bufferOffset);
    // Serialize message field [belong]
    bufferOffset = _serializer.uint8(obj.belong, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RegionOccupy
    let len;
    let data = new RegionOccupy(null);
    // Deserialize message field [status]
    data.status = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [belong]
    data.belong = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 2;
  }

  static datatype() {
    // Returns string type for a message object
    return 'simple_msgs/RegionOccupy';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'b93e8ad8a0004ce2f2e8a04d9cfaa53a';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 status
    uint8 belong
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RegionOccupy(null);
    if (msg.status !== undefined) {
      resolved.status = msg.status;
    }
    else {
      resolved.status = 0
    }

    if (msg.belong !== undefined) {
      resolved.belong = msg.belong;
    }
    else {
      resolved.belong = 0
    }

    return resolved;
    }
};

module.exports = RegionOccupy;
