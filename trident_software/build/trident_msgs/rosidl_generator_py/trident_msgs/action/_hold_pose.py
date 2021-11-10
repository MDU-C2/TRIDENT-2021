# generated from rosidl_generator_py/resource/_idl.py.em
# with input from trident_msgs:action/HoldPose.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HoldPose_Goal(type):
    """Metaclass of message 'HoldPose_Goal'."""

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
                'trident_msgs.action.HoldPose_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hold_pose__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hold_pose__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hold_pose__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__hold_pose__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hold_pose__goal

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HoldPose_Goal(metaclass=Metaclass_HoldPose_Goal):
    """Message class 'HoldPose_Goal'."""

    __slots__ = [
        '_pose',
        '_duration',
    ]

    _fields_and_field_types = {
        'pose': 'geometry_msgs/Pose',
        'duration': 'int64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from geometry_msgs.msg import Pose
        self.pose = kwargs.get('pose', Pose())
        self.duration = kwargs.get('duration', int())

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
        if self.pose != other.pose:
            return False
        if self.duration != other.duration:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def pose(self):
        """Message field 'pose'."""
        return self._pose

    @pose.setter
    def pose(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose' field must be a sub message of type 'Pose'"
        self._pose = value

    @property
    def duration(self):
        """Message field 'duration'."""
        return self._duration

    @duration.setter
    def duration(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'duration' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'duration' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._duration = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_HoldPose_Result(type):
    """Metaclass of message 'HoldPose_Result'."""

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
                'trident_msgs.action.HoldPose_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hold_pose__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hold_pose__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hold_pose__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__hold_pose__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hold_pose__result

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HoldPose_Result(metaclass=Metaclass_HoldPose_Result):
    """Message class 'HoldPose_Result'."""

    __slots__ = [
        '_duration',
        '_status',
        '_message',
        '_pose_mean',
        '_pose_variance',
    ]

    _fields_and_field_types = {
        'duration': 'int64',
        'status': 'int16',
        'message': 'string',
        'pose_mean': 'geometry_msgs/Pose',
        'pose_variance': 'geometry_msgs/Pose',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.duration = kwargs.get('duration', int())
        self.status = kwargs.get('status', int())
        self.message = kwargs.get('message', str())
        from geometry_msgs.msg import Pose
        self.pose_mean = kwargs.get('pose_mean', Pose())
        from geometry_msgs.msg import Pose
        self.pose_variance = kwargs.get('pose_variance', Pose())

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
        if self.duration != other.duration:
            return False
        if self.status != other.status:
            return False
        if self.message != other.message:
            return False
        if self.pose_mean != other.pose_mean:
            return False
        if self.pose_variance != other.pose_variance:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def duration(self):
        """Message field 'duration'."""
        return self._duration

    @duration.setter
    def duration(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'duration' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'duration' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._duration = value

    @property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'status' field must be an integer in [-32768, 32767]"
        self._status = value

    @property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

    @property
    def pose_mean(self):
        """Message field 'pose_mean'."""
        return self._pose_mean

    @pose_mean.setter
    def pose_mean(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose_mean' field must be a sub message of type 'Pose'"
        self._pose_mean = value

    @property
    def pose_variance(self):
        """Message field 'pose_variance'."""
        return self._pose_variance

    @pose_variance.setter
    def pose_variance(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose_variance' field must be a sub message of type 'Pose'"
        self._pose_variance = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_HoldPose_Feedback(type):
    """Metaclass of message 'HoldPose_Feedback'."""

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
                'trident_msgs.action.HoldPose_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hold_pose__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hold_pose__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hold_pose__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__hold_pose__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hold_pose__feedback

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HoldPose_Feedback(metaclass=Metaclass_HoldPose_Feedback):
    """Message class 'HoldPose_Feedback'."""

    __slots__ = [
        '_status',
        '_message',
        '_pose_mean',
        '_pose_variance',
    ]

    _fields_and_field_types = {
        'status': 'int16',
        'message': 'string',
        'pose_mean': 'geometry_msgs/Pose',
        'pose_variance': 'geometry_msgs/Pose',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        self.message = kwargs.get('message', str())
        from geometry_msgs.msg import Pose
        self.pose_mean = kwargs.get('pose_mean', Pose())
        from geometry_msgs.msg import Pose
        self.pose_variance = kwargs.get('pose_variance', Pose())

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
        if self.status != other.status:
            return False
        if self.message != other.message:
            return False
        if self.pose_mean != other.pose_mean:
            return False
        if self.pose_variance != other.pose_variance:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -32768 and value < 32768, \
                "The 'status' field must be an integer in [-32768, 32767]"
        self._status = value

    @property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

    @property
    def pose_mean(self):
        """Message field 'pose_mean'."""
        return self._pose_mean

    @pose_mean.setter
    def pose_mean(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose_mean' field must be a sub message of type 'Pose'"
        self._pose_mean = value

    @property
    def pose_variance(self):
        """Message field 'pose_variance'."""
        return self._pose_variance

    @pose_variance.setter
    def pose_variance(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'pose_variance' field must be a sub message of type 'Pose'"
        self._pose_variance = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_HoldPose_SendGoal_Request(type):
    """Metaclass of message 'HoldPose_SendGoal_Request'."""

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
                'trident_msgs.action.HoldPose_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hold_pose__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hold_pose__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hold_pose__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__hold_pose__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hold_pose__send_goal__request

            from trident_msgs.action import HoldPose
            if HoldPose.Goal.__class__._TYPE_SUPPORT is None:
                HoldPose.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HoldPose_SendGoal_Request(metaclass=Metaclass_HoldPose_SendGoal_Request):
    """Message class 'HoldPose_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'trident_msgs/HoldPose_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['trident_msgs', 'action'], 'HoldPose_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from trident_msgs.action._hold_pose import HoldPose_Goal
        self.goal = kwargs.get('goal', HoldPose_Goal())

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
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from trident_msgs.action._hold_pose import HoldPose_Goal
            assert \
                isinstance(value, HoldPose_Goal), \
                "The 'goal' field must be a sub message of type 'HoldPose_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_HoldPose_SendGoal_Response(type):
    """Metaclass of message 'HoldPose_SendGoal_Response'."""

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
                'trident_msgs.action.HoldPose_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hold_pose__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hold_pose__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hold_pose__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__hold_pose__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hold_pose__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HoldPose_SendGoal_Response(metaclass=Metaclass_HoldPose_SendGoal_Response):
    """Message class 'HoldPose_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

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
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_HoldPose_SendGoal(type):
    """Metaclass of service 'HoldPose_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trident_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trident_msgs.action.HoldPose_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__hold_pose__send_goal

            from trident_msgs.action import _hold_pose
            if _hold_pose.Metaclass_HoldPose_SendGoal_Request._TYPE_SUPPORT is None:
                _hold_pose.Metaclass_HoldPose_SendGoal_Request.__import_type_support__()
            if _hold_pose.Metaclass_HoldPose_SendGoal_Response._TYPE_SUPPORT is None:
                _hold_pose.Metaclass_HoldPose_SendGoal_Response.__import_type_support__()


class HoldPose_SendGoal(metaclass=Metaclass_HoldPose_SendGoal):
    from trident_msgs.action._hold_pose import HoldPose_SendGoal_Request as Request
    from trident_msgs.action._hold_pose import HoldPose_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_HoldPose_GetResult_Request(type):
    """Metaclass of message 'HoldPose_GetResult_Request'."""

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
                'trident_msgs.action.HoldPose_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hold_pose__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hold_pose__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hold_pose__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__hold_pose__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hold_pose__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HoldPose_GetResult_Request(metaclass=Metaclass_HoldPose_GetResult_Request):
    """Message class 'HoldPose_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

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
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_HoldPose_GetResult_Response(type):
    """Metaclass of message 'HoldPose_GetResult_Response'."""

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
                'trident_msgs.action.HoldPose_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hold_pose__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hold_pose__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hold_pose__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__hold_pose__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hold_pose__get_result__response

            from trident_msgs.action import HoldPose
            if HoldPose.Result.__class__._TYPE_SUPPORT is None:
                HoldPose.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HoldPose_GetResult_Response(metaclass=Metaclass_HoldPose_GetResult_Response):
    """Message class 'HoldPose_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'trident_msgs/HoldPose_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['trident_msgs', 'action'], 'HoldPose_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from trident_msgs.action._hold_pose import HoldPose_Result
        self.result = kwargs.get('result', HoldPose_Result())

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
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from trident_msgs.action._hold_pose import HoldPose_Result
            assert \
                isinstance(value, HoldPose_Result), \
                "The 'result' field must be a sub message of type 'HoldPose_Result'"
        self._result = value


class Metaclass_HoldPose_GetResult(type):
    """Metaclass of service 'HoldPose_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trident_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trident_msgs.action.HoldPose_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__hold_pose__get_result

            from trident_msgs.action import _hold_pose
            if _hold_pose.Metaclass_HoldPose_GetResult_Request._TYPE_SUPPORT is None:
                _hold_pose.Metaclass_HoldPose_GetResult_Request.__import_type_support__()
            if _hold_pose.Metaclass_HoldPose_GetResult_Response._TYPE_SUPPORT is None:
                _hold_pose.Metaclass_HoldPose_GetResult_Response.__import_type_support__()


class HoldPose_GetResult(metaclass=Metaclass_HoldPose_GetResult):
    from trident_msgs.action._hold_pose import HoldPose_GetResult_Request as Request
    from trident_msgs.action._hold_pose import HoldPose_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_HoldPose_FeedbackMessage(type):
    """Metaclass of message 'HoldPose_FeedbackMessage'."""

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
                'trident_msgs.action.HoldPose_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hold_pose__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hold_pose__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hold_pose__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__hold_pose__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hold_pose__feedback_message

            from trident_msgs.action import HoldPose
            if HoldPose.Feedback.__class__._TYPE_SUPPORT is None:
                HoldPose.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HoldPose_FeedbackMessage(metaclass=Metaclass_HoldPose_FeedbackMessage):
    """Message class 'HoldPose_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'trident_msgs/HoldPose_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['trident_msgs', 'action'], 'HoldPose_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from trident_msgs.action._hold_pose import HoldPose_Feedback
        self.feedback = kwargs.get('feedback', HoldPose_Feedback())

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
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from trident_msgs.action._hold_pose import HoldPose_Feedback
            assert \
                isinstance(value, HoldPose_Feedback), \
                "The 'feedback' field must be a sub message of type 'HoldPose_Feedback'"
        self._feedback = value


class Metaclass_HoldPose(type):
    """Metaclass of action 'HoldPose'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trident_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trident_msgs.action.HoldPose')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__hold_pose

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from trident_msgs.action import _hold_pose
            if _hold_pose.Metaclass_HoldPose_SendGoal._TYPE_SUPPORT is None:
                _hold_pose.Metaclass_HoldPose_SendGoal.__import_type_support__()
            if _hold_pose.Metaclass_HoldPose_GetResult._TYPE_SUPPORT is None:
                _hold_pose.Metaclass_HoldPose_GetResult.__import_type_support__()
            if _hold_pose.Metaclass_HoldPose_FeedbackMessage._TYPE_SUPPORT is None:
                _hold_pose.Metaclass_HoldPose_FeedbackMessage.__import_type_support__()


class HoldPose(metaclass=Metaclass_HoldPose):

    # The goal message defined in the action definition.
    from trident_msgs.action._hold_pose import HoldPose_Goal as Goal
    # The result message defined in the action definition.
    from trident_msgs.action._hold_pose import HoldPose_Result as Result
    # The feedback message defined in the action definition.
    from trident_msgs.action._hold_pose import HoldPose_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from trident_msgs.action._hold_pose import HoldPose_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from trident_msgs.action._hold_pose import HoldPose_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from trident_msgs.action._hold_pose import HoldPose_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
