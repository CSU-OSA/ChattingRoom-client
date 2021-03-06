# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: Request.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database

# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()

DESCRIPTOR = _descriptor.FileDescriptor(
  name='Request.proto',
  package='proto.request',
  syntax='proto3',
  serialized_options=b'H\001',
  create_key=_descriptor._internal_create_key,
  serialized_pb=b'\n\rRequest.proto\x12\rproto.request\"\xbd\x03\n\x0b\x43ommandPOJO\x12\x37\n\toperation\x18\x01 \x01(\x0e\x32$.proto.request.CommandPOJO.Operation\x12,\n\x07message\x18\x02 \x01(\x0b\x32\x16.proto.request.MessageH\x00\x88\x01\x01\x12,\n\x07\x63hannel\x18\x03 \x01(\x0b\x32\x16.proto.request.ChannelH\x01\x88\x01\x01\x12.\n\x08register\x18\x04 \x01(\x0b\x32\x17.proto.request.RegisterH\x02\x88\x01\x01\"\xc3\x01\n\tOperation\x12\n\n\x06RETAIN\x10\x00\x12\t\n\x05LOGIN\x10\x01\x12\n\n\x06LOGOUT\x10\x02\x12\x07\n\x03REG\x10\x03\x12\x0c\n\x08JOIN_CHA\x10\x04\x12\x0c\n\x08QUIT_CHA\x10\x05\x12\x0e\n\nCREATE_CHA\x10\x06\x12\x0b\n\x07SENDMSG\x10\x07\x12\n\n\x06GETMSG\x10\x08\x12\r\n\tHEARTBEAT\x10\t\x12\x0b\n\x07VERSION\x10\n\x12\x14\n\x10GET_CHANNEL_LIST\x10\x0b\x12\x13\n\x0fGET_MEMBER_LIST\x10\x0c\x42\n\n\x08_messageB\n\n\x08_channelB\x0b\n\t_register\"V\n\x07\x43hannel\x12\x0f\n\x07\x63hannel\x18\x01 \x01(\t\x12\x13\n\x06ticket\x18\x02 \x01(\tH\x00\x88\x01\x01\x12\x11\n\x04nick\x18\x03 \x01(\tH\x01\x88\x01\x01\x42\t\n\x07_ticketB\x07\n\x05_nick\"+\n\x07Message\x12\x0f\n\x07\x63hannel\x18\x01 \x01(\t\x12\x0f\n\x07\x63ontent\x18\x03 \x01(\t\"4\n\x08Register\x12\x0c\n\x04uuid\x18\x01 \x01(\t\x12\x11\n\x04nick\x18\x02 \x01(\tH\x00\x88\x01\x01\x42\x07\n\x05_nickB\x02H\x01\x62\x06proto3'
)

_COMMANDPOJO_OPERATION = _descriptor.EnumDescriptor(
  name='Operation',
  full_name='proto.request.CommandPOJO.Operation',
  filename=None,
  file=DESCRIPTOR,
  create_key=_descriptor._internal_create_key,
  values=[
    _descriptor.EnumValueDescriptor(
      name='RETAIN', index=0, number=0,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='LOGIN', index=1, number=1,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='LOGOUT', index=2, number=2,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='REG', index=3, number=3,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='JOIN_CHA', index=4, number=4,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='QUIT_CHA', index=5, number=5,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='CREATE_CHA', index=6, number=6,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='SENDMSG', index=7, number=7,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='GETMSG', index=8, number=8,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='HEARTBEAT', index=9, number=9,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='VERSION', index=10, number=10,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='GET_CHANNEL_LIST', index=11, number=11,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
    _descriptor.EnumValueDescriptor(
      name='GET_MEMBER_LIST', index=12, number=12,
      serialized_options=None,
      type=None,
      create_key=_descriptor._internal_create_key),
  ],
  containing_type=None,
  serialized_options=None,
  serialized_start=246,
  serialized_end=441,
)
_sym_db.RegisterEnumDescriptor(_COMMANDPOJO_OPERATION)

_COMMANDPOJO = _descriptor.Descriptor(
  name='CommandPOJO',
  full_name='proto.request.CommandPOJO',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='operation', full_name='proto.request.CommandPOJO.operation', index=0,
      number=1, type=14, cpp_type=8, label=1,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR, create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='message', full_name='proto.request.CommandPOJO.message', index=1,
      number=2, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR, create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='channel', full_name='proto.request.CommandPOJO.channel', index=2,
      number=3, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR, create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='register', full_name='proto.request.CommandPOJO.register', index=3,
      number=4, type=11, cpp_type=10, label=1,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR, create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
    _COMMANDPOJO_OPERATION,
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
    _descriptor.OneofDescriptor(
      name='_message', full_name='proto.request.CommandPOJO._message',
      index=0, containing_type=None,
      create_key=_descriptor._internal_create_key,
      fields=[]),
    _descriptor.OneofDescriptor(
      name='_channel', full_name='proto.request.CommandPOJO._channel',
      index=1, containing_type=None,
      create_key=_descriptor._internal_create_key,
      fields=[]),
    _descriptor.OneofDescriptor(
      name='_register', full_name='proto.request.CommandPOJO._register',
      index=2, containing_type=None,
      create_key=_descriptor._internal_create_key,
      fields=[]),
  ],
  serialized_start=33,
  serialized_end=478,
)

_CHANNEL = _descriptor.Descriptor(
  name='Channel',
  full_name='proto.request.Channel',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='channel', full_name='proto.request.Channel.channel', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR, create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='ticket', full_name='proto.request.Channel.ticket', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR, create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='nick', full_name='proto.request.Channel.nick', index=2,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR, create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
    _descriptor.OneofDescriptor(
      name='_ticket', full_name='proto.request.Channel._ticket',
      index=0, containing_type=None,
      create_key=_descriptor._internal_create_key,
      fields=[]),
    _descriptor.OneofDescriptor(
      name='_nick', full_name='proto.request.Channel._nick',
      index=1, containing_type=None,
      create_key=_descriptor._internal_create_key,
      fields=[]),
  ],
  serialized_start=480,
  serialized_end=566,
)

_MESSAGE = _descriptor.Descriptor(
  name='Message',
  full_name='proto.request.Message',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='channel', full_name='proto.request.Message.channel', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR, create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='content', full_name='proto.request.Message.content', index=1,
      number=3, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR, create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=568,
  serialized_end=611,
)

_REGISTER = _descriptor.Descriptor(
  name='Register',
  full_name='proto.request.Register',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  create_key=_descriptor._internal_create_key,
  fields=[
    _descriptor.FieldDescriptor(
      name='uuid', full_name='proto.request.Register.uuid', index=0,
      number=1, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR, create_key=_descriptor._internal_create_key),
    _descriptor.FieldDescriptor(
      name='nick', full_name='proto.request.Register.nick', index=1,
      number=2, type=9, cpp_type=9, label=1,
      has_default_value=False, default_value=b"".decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      serialized_options=None, file=DESCRIPTOR, create_key=_descriptor._internal_create_key),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  serialized_options=None,
  is_extendable=False,
  syntax='proto3',
  extension_ranges=[],
  oneofs=[
    _descriptor.OneofDescriptor(
      name='_nick', full_name='proto.request.Register._nick',
      index=0, containing_type=None,
      create_key=_descriptor._internal_create_key,
      fields=[]),
  ],
  serialized_start=613,
  serialized_end=665,
)

_COMMANDPOJO.fields_by_name['operation'].enum_type = _COMMANDPOJO_OPERATION
_COMMANDPOJO.fields_by_name['message'].message_type = _MESSAGE
_COMMANDPOJO.fields_by_name['channel'].message_type = _CHANNEL
_COMMANDPOJO.fields_by_name['register'].message_type = _REGISTER
_COMMANDPOJO_OPERATION.containing_type = _COMMANDPOJO
_COMMANDPOJO.oneofs_by_name['_message'].fields.append(
  _COMMANDPOJO.fields_by_name['message'])
_COMMANDPOJO.fields_by_name['message'].containing_oneof = _COMMANDPOJO.oneofs_by_name['_message']
_COMMANDPOJO.oneofs_by_name['_channel'].fields.append(
  _COMMANDPOJO.fields_by_name['channel'])
_COMMANDPOJO.fields_by_name['channel'].containing_oneof = _COMMANDPOJO.oneofs_by_name['_channel']
_COMMANDPOJO.oneofs_by_name['_register'].fields.append(
  _COMMANDPOJO.fields_by_name['register'])
_COMMANDPOJO.fields_by_name['register'].containing_oneof = _COMMANDPOJO.oneofs_by_name['_register']
_CHANNEL.oneofs_by_name['_ticket'].fields.append(
  _CHANNEL.fields_by_name['ticket'])
_CHANNEL.fields_by_name['ticket'].containing_oneof = _CHANNEL.oneofs_by_name['_ticket']
_CHANNEL.oneofs_by_name['_nick'].fields.append(
  _CHANNEL.fields_by_name['nick'])
_CHANNEL.fields_by_name['nick'].containing_oneof = _CHANNEL.oneofs_by_name['_nick']
_REGISTER.oneofs_by_name['_nick'].fields.append(
  _REGISTER.fields_by_name['nick'])
_REGISTER.fields_by_name['nick'].containing_oneof = _REGISTER.oneofs_by_name['_nick']
DESCRIPTOR.message_types_by_name['CommandPOJO'] = _COMMANDPOJO
DESCRIPTOR.message_types_by_name['Channel'] = _CHANNEL
DESCRIPTOR.message_types_by_name['Message'] = _MESSAGE
DESCRIPTOR.message_types_by_name['Register'] = _REGISTER
_sym_db.RegisterFileDescriptor(DESCRIPTOR)

CommandPOJO = _reflection.GeneratedProtocolMessageType('CommandPOJO', (_message.Message,), {
  'DESCRIPTOR': _COMMANDPOJO,
  '__module__': 'Request_pb2'
  # @@protoc_insertion_point(class_scope:proto.request.CommandPOJO)
})
_sym_db.RegisterMessage(CommandPOJO)

Channel = _reflection.GeneratedProtocolMessageType('Channel', (_message.Message,), {
  'DESCRIPTOR': _CHANNEL,
  '__module__': 'Request_pb2'
  # @@protoc_insertion_point(class_scope:proto.request.Channel)
})
_sym_db.RegisterMessage(Channel)

Message = _reflection.GeneratedProtocolMessageType('Message', (_message.Message,), {
  'DESCRIPTOR': _MESSAGE,
  '__module__': 'Request_pb2'
  # @@protoc_insertion_point(class_scope:proto.request.Message)
})
_sym_db.RegisterMessage(Message)

Register = _reflection.GeneratedProtocolMessageType('Register', (_message.Message,), {
  'DESCRIPTOR': _REGISTER,
  '__module__': 'Request_pb2'
  # @@protoc_insertion_point(class_scope:proto.request.Register)
})
_sym_db.RegisterMessage(Register)

DESCRIPTOR._options = None
# @@protoc_insertion_point(module_scope)
