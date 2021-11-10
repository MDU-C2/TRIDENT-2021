# generated from rosidl_generator_py/resource/_idl.py.em
# with input from trident_msgs:msg/WaypointAction.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_WaypointAction(type):
    """Metaclass of message 'WaypointAction'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trident_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trident_msgs.msg.WaypointAction')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__waypoint_action
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__waypoint_action
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__waypoint_action
            cls._TYPE_SUPPORT = module.type_support_msg__msg__waypoint_action
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__waypoint_action

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'ACTION_TYPE__DEFAULT': 0,
            'ACTION_PARAM__DEFAULT': 0,
        }

    @property
    def ACTION_TYPE__DEFAULT(cls):
        """Return default value for message field 'action_type'."""
        return 0

    @property
    def ACTION_PARAM__DEFAULT(cls):
        """Return default value for message field 'action_param'."""
        return 0


class WaypointAction(metaclass=Metaclass_WaypointAction):
    """Message class 'WaypointAction'."""

    __slots__ = [
        '_action_type',
        '_action_param',
    ]

    _fields_and_field_types = {
        'action_type': 'int16',
        'action_param': 'int16',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.action_type = kwargs.get(
            'action_type', WaypointAction.ACTION_TYPE__DEFAULT)
        self.action_param = kwargs.get(
            'action_param', WaypointAction.ACTION_PARAM__DEFAULT)

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.action_type != other.action_type:
            return False
        if self.action_param != other.action_param:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def action_type(self):
        """Message field 'action_type'."""
        return self._action_type

    @action_type.setter
    def action_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'action_type' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'action_type' field must be an integer in [-32768, 32767]"
        self._action_type = value

    @property
    def action_param(self):
        """Message field 'action_param'."""
        return self._action_param

    @action_param.setter
    def action_param(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'action_param' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'action_param' field must be an integer in [-32768, 32767]"
        self._action_param = value
