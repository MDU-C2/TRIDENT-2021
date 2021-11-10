# generated from rosidl_generator_py/resource/_idl.py.em
# with input from trident_msgs:srv/KalmanSensorService.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'state'
# Member 'covar'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_KalmanSensorService_Request(type):
    """Metaclass of message 'KalmanSensorService_Request'."""

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
                'trident_msgs.srv.KalmanSensorService_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__kalman_sensor_service__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__kalman_sensor_service__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__kalman_sensor_service__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__kalman_sensor_service__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__kalman_sensor_service__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class KalmanSensorService_Request(metaclass=Metaclass_KalmanSensorService_Request):
    """Message class 'KalmanSensorService_Request'."""

    __slots__ = [
        '_state',
        '_covar',
    ]

    _fields_and_field_types = {
        'state': 'sequence<float>',
        'covar': 'sequence<float>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.state = array.array('f', kwargs.get('state', []))
        self.covar = array.array('f', kwargs.get('covar', []))

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
        if self.state != other.state:
            return False
        if self.covar != other.covar:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def state(self):
        """Message field 'state'."""
        return self._state

    @state.setter
    def state(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'state' array.array() must have the type code of 'f'"
            self._state = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'state' field must be a set or sequence and each value of type 'float'"
        self._state = array.array('f', value)

    @property
    def covar(self):
        """Message field 'covar'."""
        return self._covar

    @covar.setter
    def covar(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'covar' array.array() must have the type code of 'f'"
            self._covar = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'covar' field must be a set or sequence and each value of type 'float'"
        self._covar = array.array('f', value)


# Import statements for member types

# Member 'residual'
# Member 'gain'
# Member 'observationmatrix'
# already imported above
# import array

# already imported above
# import rosidl_parser.definition


class Metaclass_KalmanSensorService_Response(type):
    """Metaclass of message 'KalmanSensorService_Response'."""

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
                'trident_msgs.srv.KalmanSensorService_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__kalman_sensor_service__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__kalman_sensor_service__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__kalman_sensor_service__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__kalman_sensor_service__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__kalman_sensor_service__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class KalmanSensorService_Response(metaclass=Metaclass_KalmanSensorService_Response):
    """Message class 'KalmanSensorService_Response'."""

    __slots__ = [
        '_residual',
        '_gain',
        '_observationmatrix',
    ]

    _fields_and_field_types = {
        'residual': 'sequence<float>',
        'gain': 'sequence<float>',
        'observationmatrix': 'sequence<float>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.residual = array.array('f', kwargs.get('residual', []))
        self.gain = array.array('f', kwargs.get('gain', []))
        self.observationmatrix = array.array('f', kwargs.get('observationmatrix', []))

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
        if self.residual != other.residual:
            return False
        if self.gain != other.gain:
            return False
        if self.observationmatrix != other.observationmatrix:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def residual(self):
        """Message field 'residual'."""
        return self._residual

    @residual.setter
    def residual(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'residual' array.array() must have the type code of 'f'"
            self._residual = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'residual' field must be a set or sequence and each value of type 'float'"
        self._residual = array.array('f', value)

    @property
    def gain(self):
        """Message field 'gain'."""
        return self._gain

    @gain.setter
    def gain(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'gain' array.array() must have the type code of 'f'"
            self._gain = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'gain' field must be a set or sequence and each value of type 'float'"
        self._gain = array.array('f', value)

    @property
    def observationmatrix(self):
        """Message field 'observationmatrix'."""
        return self._observationmatrix

    @observationmatrix.setter
    def observationmatrix(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'observationmatrix' array.array() must have the type code of 'f'"
            self._observationmatrix = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'observationmatrix' field must be a set or sequence and each value of type 'float'"
        self._observationmatrix = array.array('f', value)


class Metaclass_KalmanSensorService(type):
    """Metaclass of service 'KalmanSensorService'."""

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
                'trident_msgs.srv.KalmanSensorService')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__kalman_sensor_service

            from trident_msgs.srv import _kalman_sensor_service
            if _kalman_sensor_service.Metaclass_KalmanSensorService_Request._TYPE_SUPPORT is None:
                _kalman_sensor_service.Metaclass_KalmanSensorService_Request.__import_type_support__()
            if _kalman_sensor_service.Metaclass_KalmanSensorService_Response._TYPE_SUPPORT is None:
                _kalman_sensor_service.Metaclass_KalmanSensorService_Response.__import_type_support__()


class KalmanSensorService(metaclass=Metaclass_KalmanSensorService):
    from trident_msgs.srv._kalman_sensor_service import KalmanSensorService_Request as Request
    from trident_msgs.srv._kalman_sensor_service import KalmanSensorService_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
